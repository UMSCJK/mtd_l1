#include <stdio.h>

int main()
{
    int a;

    printf("input non-negative number:\n");
    scanf("%d", &a);

    printf("the value of `a` is %d\n", a);

    int* pa = &a;
    printf("the pointer value is %p\n", pa);

    int secondNumber;
    printf("input a number:\n");
    scanf("%d", &secondNumber);
    printf("the value of `secondNumber` is %d\n", secondNumber);
    return 0;
}