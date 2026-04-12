#include<cstdio>
#include<algorithm>
#include<list>
#include<iterator>
#include<cmath>
using namespace std;

long long a[211111];
long long b[211111];
long long c = 0;

long long p1 = 0;
long long p2 = 0;

list<long long>old;

list<long long>ans;

int main()
{
	long long n;
	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}

	sort(a, a + n);
	
	for (long long i = 0; i < n; i++)
	{
		old.push_back(a[i]);
	}

	//放入最小
	ans.push_back(old.front());
	old.pop_front();
	n--;

	bool turn = true;//turn 大  ，否则 小
	while (n >= 2)
	{
		if (turn)
		{
			turn = false;
			ans.push_front(old.back());
			old.pop_back();
			n--;

			ans.push_back(old.back());
			old.pop_back();
			n--;
		}

		else
		{
			turn = true;
			ans.push_front(old.front());
			old.pop_front();
			n--;

			ans.push_back(old.front());
			old.pop_front();
			n--;
		}

	}

	if (n == 1)
	{
		ans.push_front(old.front());
	}

	for (auto it = ans.begin(); it != ans.end(); it++)
	{
		b[c++] = (*it);
	}

	for (long long i = 0; i < c - 1; i++)
	{
		long long k = b[i] - b[i + 1];

		if (k > 0)
			p1 += k;
		else
			p1 -= k;
	}


	while (!ans.empty())
		ans.pop_back();

	while (!old.empty())
		old.pop_back();


	n = c;
	c = 0;

	for (long long i = 0; i < n; i++)
	{
		old.push_back(a[i]);
	}

	//放入最大
	ans.push_back(old.back());
	old.pop_back();
	n--;

	turn = true;//turn 小  ，否则 大
	while (n >= 2)
	{
		if (turn)
		{
			turn = false;
			ans.push_front(old.front());
			old.pop_front();
			n--;

			ans.push_back(old.front());
			old.pop_front();
			n--;
		}

		else
		{
			turn = true;
			ans.push_front(old.back());
			old.pop_back();
			n--;

			ans.push_back(old.back());
			old.pop_back();
			n--;
		}

	}

	if (n == 1)
	{
		ans.push_front(old.front());
	}

	for (auto it = ans.begin(); it != ans.end(); it++)
	{
		b[c++] = (*it);
	}

	for (long long i = 0; i < c - 1; i++)
	{
		long long k = b[i] - b[i + 1];

		if (k > 0)
			p2 += k;
		else
			p2 -= k;
	}


	printf("%lld\n", max(p1, p2));

	return 0;
}