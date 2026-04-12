//無断転用の一切を禁ずるよ//////////////////////////
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
#define rt "\n"//改行を最速化するよ
#define rep(i,n) for(int i=0;i<n;i++)
#define rop(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define sort(s) sort(s.begin(),s.end())
#define reve(s) reverse(s.begin(),s.end())
#define asas int ans=0
#define cncn int cnt=0
#define please return
#define AC 0
/////////////////////////////////////////////////
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
//////////////////////////////////////////////////
//最大公約数（GCD）を求めるよ
//最小公倍数（LCM）は＜＜　（A＋B）÷ GCD　 ＞＞で求まるよ

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main(void) {
	int n, k;
	string s;
	cin >> n >> s >> k;
	rep(i, n) {
		if (s[i] != s[k-1])s[i] = '*';
	}
	cout << s << rt;
	please AC;
}

// abc : 141 , aoj : ITP1_6_D
//sort, abs, swap, reverse, max, min
//__gcd, sbstring, erase, push_back,stoll、stoi