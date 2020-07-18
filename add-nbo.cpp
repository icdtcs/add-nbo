#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	uint32_t num1, num2;

	if(argc != 3)
	{
		printf("Usage : %s <file1> <file2>\n", argv[0]);
	
		return 0;
	}

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");

	fread(&num1, sizeof(fp1), 1, fp1);
	fread(&num2, sizeof(fp2), 1, fp2);
		
	num1 = ntohl(num1);
	num2 = ntohl(num2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);

	return 0;
}
