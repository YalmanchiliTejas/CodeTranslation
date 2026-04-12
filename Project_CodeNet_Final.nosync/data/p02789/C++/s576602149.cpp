//保留所有权利。
#include<iostream>
#include<stdio.h>//printするよ
#include<vector>
#include<algorithm>//辞書順はnext_permutationだよ
#include<set>
#include<string>
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
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define vcin(V) for (int i = 0; i < (V).size(); i++) { cin >> (V).at(i); }
#define sort(s) sort(s.begin(),s.end())
#define reve(s) reverse(s.begin(),s.end())
#define asas int ans=0
#define cncn int cnt=0
#define smsm int sum=0
#define nn int n=0
#define please return
#define AC 0//おまじないだよ
#define Rapid cin.tie(0);ios::sync_with_stdio(false)
//END OF DEFINE.
using namespace std;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vcha;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool; 
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
//BEGIN OF CODE.
int a = 0, b = 0, c = 0, cnt = 0, ans = 0, n = 0;
string s, t;
int main(void){
	int m;
	cin >> n >> m;
	Yes(n == m);
	please AC;
}
//THE END.