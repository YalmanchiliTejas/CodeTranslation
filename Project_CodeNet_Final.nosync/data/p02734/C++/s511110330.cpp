#pragma gcc optimize(2)
#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <ctime>
//#include <unordered_map>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <cassert>
#include <complex>
using namespace std;
#define maxn 200007
#define maxm 400007
#define maxq 1000007
#define maxl 1234
#define modn 998244353
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define scanl2(a,b) scanf("%lld%lld",&a,&b)
#define scans(a) scanf("%s",a)
#define scans2(a,b) scanf("%s%s",a,b)
#define scand(a) scanf("%lf",&a)
#define scan2(a,b) scanf("%d%d",&a,&b)
#define scand2(a,b) scanf("%lf%lf",&a,&b)
#define scan3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scan4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define print(a) printf("%d\n",a);
#define printl(a) printf("%lld\n",a);
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>= b;i--)
#define fscan(a) fscanf(stream,"%d", &a);
#define mp      make_pair	
#define pb      push_back
#define eb      emplace_back
#define mm(a,b) memset(a,b,sizeof a)
#define log2(n) (double)(log(n) / log(2.0))
#define _crt_disable_perfcrit_locks
#define bll __int128
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <char, char> mcc;
typedef pair <char, int> pci;
typedef complex<double> cd;
typedef vector<complex<double> > vcd;

const double eps = 1e-8;
const double pi = 2 * acos(0.0);

int cc, bb; char ch; inline int F() {
	while (ch = getchar(), (ch < 48 || ch> 57) && ch != '-'); ch == '-' ? cc = bb = 0 : (cc = ch - '0', bb = 1);
	while (ch = getchar(), ch > 47 && ch < 58)cc = (cc << 1) + (cc << 3) + (ch ^ 48); return bb ? cc : -cc;
}
void write(int x) {
	int y = 10, len = 1;
	while (y <= x) { y *= 10; len++; }
	while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
}
int n;
string s;
int has1 = 0;
int sum = 0;
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//FILE* stream = fopen("L:/1.in", "rb+");
	/*int n, m;
	cin >> n >> m;
	int res = n * (n - 1) / 2 + m * (m - 1) / 2;
	cout << res << endl;*/
	/*string s;
	cin >> s;
	int isok = 1;
	string s2 = s, s3, s4,s5,s6;
	reverse(s2.begin(), s2.end());
	if (s != s2) {
		isok = 0;
	}
	else {
		s3 = s.substr(0, s.length() / 2);
		s4 = s.substr(s.length() / 2 + 1);
		s5 = s3, s6 = s4;
		reverse(s5.begin(), s5.end());
		reverse(s6.begin(), s6.end());
		if (s5 != s3 || s6 != s4)
			isok = 0;
	}
	if (isok)cout << "Yes" << endl;
	else cout << "No" << endl;*/
	/*int l;
	cin >> l;
	double len = l / 3.0;
	len = len * len * len;
	printf("%lf", len);*/
	/*int n;
	ll a[maxn];
	ll num[maxn];
	memset(num, 0, sizeof num);
	cin >> n;
	for (int i = 0; i < n ; i++){
		cin >> a[i];
		num[a[i]]++;
	}
	ll res = 0;
	for (int i = 1; i <= n ; i++){
		res += num[i] * (num[i] - 1) / 2;
	}
	for (int i = 0; i < n ; i++){
		res-= num[a[i]] * (num[a[i]] - 1) / 2;
		num[a[i]]--;
		res += num[a[i]] * (num[a[i]] - 1) / 2;
		cout << res << endl;
		res -= num[a[i]] * (num[a[i]] - 1) / 2;
		num[a[i]]++;
		res += num[a[i]] * (num[a[i]] - 1) / 2;
	}*/
	int dp[3007][3];//l,r能得到k的数量
	int n, s;
	int a[3007];
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll res = 0;
	memset(dp, 0, sizeof dp);//dp[k][1]表示确定L能得到k的方案数 dp[k][2]表示确定L和R能得到k的方案数
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = s; k >= 0; k--) {
			dp[k][1] = (dp[k][0] + dp[k][1]) % modn;
			dp[k][2] = (dp[k][1] + dp[k][2]) % modn;
			if (k - a[i] >= 0) {
				(dp[k][1] += dp[k - a[i]][0] + dp[k - a[i]][1]) %= modn;
				(dp[k][2] += dp[k - a[i]][0] + dp[k - a[i]][1]) %= modn;
			}
		}
	}
	cout << dp[s][2] << endl;
	return 0;
}