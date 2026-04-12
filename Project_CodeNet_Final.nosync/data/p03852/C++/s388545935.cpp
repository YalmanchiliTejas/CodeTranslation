//保留所有权利。
#include<iostream>
#include<stdio.h>//printするよ
#include<vector>
#include<algorithm>//辞書順はnext_permutationだよ
#include<set>
#include<string>
#include<sstream>
#include<string.h>
#include<time.h>
#include<random>
#include<cmath>
#include<math.h>
#include<queue>
#include<time.h>
#include<iomanip>
#include<utility>//swapで数値交換するよ
//END OF LIBRARIES.
#define rt "\n"//改行を最速化させるよ
#define rep(i,n) for(int i=0;i<n;i++)
#define rop(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define drop(i,n) for(int i=n;0<i;i--)
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define sec(a,b,ans) if(ans)cout<<a<<rt;else cout<<b<<rt;
#define vcin(s,n) rep(i,n)cin>>s[i];//vcin(配列名),(繰り返し回数)
#define vcin(v) for (int i = 0; i < (v).size(); i++) { cin >> (v)[i]; }
#define sort(s) sort(s.begin(),s.end())
#define reve(s) reverse(s.begin(),s.end())
#define asas int ans=0
#define llcncn llint cnt=0
#define llasas llint ans=0
#define cncn int cnt=0
#define smsm int sum=0
#define str srting
#define v vector
#define please return
#define AC 0//おまじないだよ
#define Rapid cin.tie(0);ios::sync_with_stdio(false)
//END OF DEFINE.
using namespace std;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vcha;
typedef vector<double> vdou;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<string>> vvstr;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;
//printf("%02d:%02d:%02d\n", h, m, s);・・・2文字は埋める・h、m、ｓ
//END OF TYPEDEF.

//最大公約数（GCD）を求めるよ
//最小公倍数（LCM）は＜＜　A × B ÷ GCD　 ＞＞で求まるよ

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

//for A以上B未満でI探索 for (int I = A; i <= B; i++)
//string s = to_string(i);
int a = 0, b = 0, c = 0, x = 0, y = 0, z = 0, n = 0, sum = 0, i = 0;
string s = ""; asas; cncn;

int main(void) {
	char c;
	cin >> c;
	if (c == 'a')cnt++;
	if (c == 'e')cnt++;
	if (c == 'i')cnt++;
	if (c == 'o')cnt++;
	if (c == 'u')cnt++;
	if (cnt != 0) {
		cout << "vowel" << rt;
	}
	else cout << "consonant" << rt;//consonantのスペル違ったやんけ(-_-メ)
	please AC;
}