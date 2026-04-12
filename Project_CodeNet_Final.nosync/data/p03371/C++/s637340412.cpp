#include<iostream>
using namespace std;
int main()
{
	int a, b, c, x, y,sum=0;
	cin >> a >> b >> c >> x >> y;
	int max = x > y ? x : y;
	for (int i = 0; i <= max * 2; i+=2)
	{
		int temp = i * c;
		if (i / 2 < x) temp += (x - i / 2)*a;
		if(i/2<y)temp+= +(y - i / 2)*b;
		if (sum==0||temp < sum)sum = temp;
	}
	printf("%d", sum);
	return 0;
}