#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
1500 2000 1600 3 2
)");
#define cin input
#endif

int main()
{
	int a, b, c, x, y, sum;
	cin >> a >> b >> c >> x >> y;
	int suma, sumb;
	suma = sumb = 0;

	suma = a+b;
	sumb = c*2;

	if (suma < sumb)
		sum = suma * min(x,y);
	else
		sum = sumb * min(x,y);

	if (x > y)
	{
		if (a < c*2)
			sum += a*(x-y);
		else
			sum += c*2*(x-y);
	}
	else
	{
		if (b < c*2)
			sum += b*(y-x);
		else
			sum += c*2*(y-x);
	}

	cout << sum << endl;
}