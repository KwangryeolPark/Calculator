#include <stdio.h>
void cal(double, double);

double x = 0, y = 0, z = 0, result;
char s1, s2;

int main(void) {

	scanf("%lf %c %lf %c %lf", &x, &s1, &y, &s2, &z);

	if(s1 == '*')	cal(x*y, 0);
	else if(s1 == '/')	cal(x/y, 0);
	else (s1 == '+') ? cal(y, x) : cal(-y, x);

	printf("Result = %G", result);
}

void cal(double x1, double x2) {
	result = x1;
	if(s2 == '*') result *= z;
	else if(s2 == '/') result /= z;
	else result += (s2 == '+') ? z : (-z);
	result += x2;
}
