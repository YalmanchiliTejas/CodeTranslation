	#include <bits/stdc++.h>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int tam = 10000010;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n, x;
	cin>>n>>x;
	ll can[n+2], pe[n+2];
	can[0] = pe[0] = 1;
	fore(i, 1, n+2) can[i] = can[i-1] * 2 + 3, pe[i] = pe[i-1] * 2 + 1;
	ll res = 0;
	while(x > 0)
	{
		while(x < can[n] && x > 0)
		{
			x--, n--;
		}
		if(x == 0) break;
		x -= can[n];
		res += pe[n];
		if(x > 0)
			x--, res++;
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2