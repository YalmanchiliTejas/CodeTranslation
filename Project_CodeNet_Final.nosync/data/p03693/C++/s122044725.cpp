#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592654
#define fix(n) cout << fixed << setprecision(n)

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)

#define si(d)  scanf("%d",&d)
#define sll(d) scanf("%lld",&d)
#define pin(d) printf("%d\n",d)
#define pln(d) printf("%lld\n",d)
#define nl 	   printf("\n")

#define ll long long
#define ull unsigned long long

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define vi vector<int>
#define pii pair<int,int> 
#define piii pair<pair<int,int>,int> 
#define all(v) v.begin(), v.end()

#define chalne_de continue
int mod=1000000007;
const int N = 1000005;

ll gcd(ll a , ll b)
{
    if ( b == 0)
    return a;
    return gcd( b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int r, g, b;
	cin >> r >> g >> b;
	int sum = r * 100 + g * 10 + b;
	if ( sum % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
