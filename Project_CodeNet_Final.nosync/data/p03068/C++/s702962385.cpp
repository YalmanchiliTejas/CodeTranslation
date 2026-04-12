#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define end "\n"
#define fi first
#define se second
#define db double
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define lowbit(x) x & (-x)
#define PII  pair<int, int> 
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i <= (b); i++)
#define Rep(i, a, b) for(int i = a; i >= (b); i--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
const db eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e4 + 5;
using namespace std;

int main()
{
	int n; cin >> n;
	cin.get();
	string s; cin >> s;
	int k; cin >> k;
	rep(i, 0, n - 1){
		if(s[i] != s[k-1]) s[i] = '*';
	}
	cout << s << endl;
	return 0;
}