#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>  
#include<cstdio>  
#include<fstream>  
#include<iomanip>
#include<algorithm>  
#include<cmath>  
#include<deque>  
#include<vector>  
#include<assert.h>
#include<bitset>
#include<queue>  
#include<string>  
#include<cstring>  
#include<map>  
#include<stack>  
#include<set>
#include<functional>
#define pii pair<int, int>
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define eps 0.00000001
#define mst(a,i) memset(a,i,sizeof(a))
#define all(n) n.begin(),n.end()
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)|1) 
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e4 + 5;
pii a[maxn];
int dp[maxn][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, k, m, n, T;
	cin >> k >> m >> n;
	int sum = k * 100 + m * 10 + n;
	if (sum % 4 == 0)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}