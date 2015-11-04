#include <iostream>

void fib(int a, int b, int c)
{
	for (int i = 0; i < i; i++)
	{
		if (i <= 1)
			c = i;
		else
		{
			c = a + b;
			a = b;
			b = c;
		}
		
	}
	std::cout << c << std::endl;
		fib(a, b, c);
}


void main() {
	int a = 0;
	int b = 1;
	int c = 0;

	fib(a, b, c);

}