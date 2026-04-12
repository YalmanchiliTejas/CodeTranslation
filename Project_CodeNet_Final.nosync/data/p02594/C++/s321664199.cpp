#include<algorithm>
#include<cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
typedef set<int>::iterator sit;
#define st first
#define sd second
#define mkp make_pair
#define pb push_back
void tempwj(){freopen("hash.in","r",stdin);freopen("hash.out","w",stdout);}
ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a % b);}
ll qpow(ll a,ll b,ll mod){a %= mod;ll ans = 1;while(b){if(b & 1)ans = ans * a % mod;a = a * a % mod;b >>= 1;}return ans;}
struct cmp{bool operator()(const pii & a, const pii & b){return a.second < b.second;}};
int lb(int x){return  x & -x;}
//friend bool operator < (Node a,Node b)   重载
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 305+10;


int main()
{
	int n;
	scanf("%d",&n);
	if(n >= 30)
		printf("Yes\n");
	else
		printf("No\n");

}

