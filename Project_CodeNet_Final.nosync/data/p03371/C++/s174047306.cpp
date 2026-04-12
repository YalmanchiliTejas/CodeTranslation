#include <iostream>

int main()
{
	int a, b, c, x, y, min0, min1, max0, max1, sum[3];
	std::cin >> a >> b >> c >> x >> y;
	if(x < y)
	{
		min0 = x;
		min1 = a;
		max0 = y;
		max1 = b;
	}else{
		min0 = y;
		min1 = b;
		max0 = x;
		max1 = a;
	}
	sum[0] = min0 * 2 * c;
	sum[0] += (max0 - min0) * max1;

	sum[1] = a * x + b * y; 

	sum [2] = max0 * 2 * c;

	if(sum[0] < sum[1] && sum[0] < sum[2])
	{
		std::cout << sum[0] << std::endl;
	}else if(sum[1] < sum[0] && sum[1] < sum[2])
	{
		std::cout << sum[1] << std::endl;
	}else{
		std::cout << sum[2] << std::endl;
	}

}