#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	printf("Данная программа переводит числа из 10-ой системы счисления в двоичную систему\nв виде обратного и дополнительного кода (+ прямой).\nВведите число: ");
	int bin = 0, k = 1;
	int num;
	scanf_s("%d", &num);
	while (num) //"функция" перевода из 10-ой СС в 2-ю
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	printf("%d\n", bin);
	int dir = 0;
	char rev[16] = {0}, add;
	if (bin < 0)
	{
		bin -= 2*bin;
		printf("%d\n", bin);
		if (bin < 10000000)
			dir = bin + 10000000;
		else if (bin > 10000000 && bin < 1000000000000000)
			dir = bin + 1000000000000000;
		else {
			printf("Ваше число слишком большое.\n");
			return 1;
		}
		printf("Прямой код: %d\n", dir);
		
		sprintf_s(rev, "%d", dir);
		printf("Обратный код: %s\n", rev);
	}

	return 0;
}
