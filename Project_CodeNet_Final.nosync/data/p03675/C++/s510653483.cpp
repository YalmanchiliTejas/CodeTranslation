#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tr(container, it) \
	for (auto it = container.begin(); it != container.end(); it++)
#define scontains(c,x) ((c).find(x) != (c).end())   //O(log n) 
#define contains(c,x) (find((c).begin(),(c).end(),x) != (c).end()) //O(n)
#define Ichar(_x) char _x;scanf("%c",&_x);
#define Iint(_x) int _x;scanf("%d",&_x); 
#define Ill(_x)  ll _x;scanf("%lld",&_x);
#define inc(a,b,x)(x)>a && (x)<b	
#define incE(a,b,x)(x)>=a && (x)<=b	
//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

vector<pair<int,int>> factorize(int n)
{
	vector<pair<int, int>> vp;
	int primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37 };
	for (int i = 0; i < 12; ++i)
	{
		int m = 0;
		while (n%primes[i]==0)
		{
			n = n / primes[i];
			m++;
		}
		if (m > 0)vp.push_back(make_pair(primes[i], m));
	}
	for(auto a :vp)
	{
		std::cout << a.first <<":" << a.second <<"\n";
	}

	return vp;

}
int main()
{
	Iint(n);
	deque<int> dq;
	bool b = 1;
	for (int i = 0; i < n; ++i)
	{
		Iint(a);
		if (b)dq.push_back(a);
		else { dq.push_front(a); }
		b = !b;
	}
	if(b)for (int i = 0; i < n; ++i)
	{
		std::cout << dq[i] <<" ";	
	}
	else {
		for (int i = n - 1; i >= 0; --i)
		{
			std::cout << dq[i] << " ";
		}
	}
	





}


