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
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
const double pi = 3.14159265358979323846;

template<typename T>
long long C(T n, T r) {
	if (n < 0 || r < 0)return 0;
	if (r > n / 2) r = n - r;
	long long ans = 1;
	for (T i = 1; i <= r; ++i) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


int a[200000];
int b[200000];
int main()
{
	Ill(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[i];
	}
	sort(a, a + n);
	ll t = a[n / 2];
	ll tt = a[n / 2 - 1];
	for (int i = 0; i < n; ++i)
	{
		if (b[i]<t)std::cout << t << "\n";
		else { std::cout << tt << "\n"; }
	}

}