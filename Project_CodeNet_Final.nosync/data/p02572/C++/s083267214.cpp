#include<iostream>
#include<stdio.h>
#include<vector>//s1.erase(n)=文字列s1の、n文字目以降削除
#include<algorithm>//辞書順=next_permutation
#include<set>
#include<string>//char 小文字のほうが32大きい
#include<sstream>
#include<string.h>
#include<complex>
#include<time.h>
#include<random>
#include<cmath>
#include<math.h>
#include<queue>
#include<time.h>
#include<iomanip>
#include<locale>
#include<utility>//swap=数値交換
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;


#define rt "\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define rop(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define drop(i,n) for(int i=n;0<i;i--)
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define sec(a,b,ans) if(ans)cout<<a<<rt;else cout<<b<<rt;
#define vcin(s,n) rep(i,n)cin>>s[i];//vcin(配列名),(繰り返し回数)
#define sort(s) sort(s.begin(),s.end())//標準=昇順
#define reve(s) reverse(s.begin(),s.end())
#define asas int ans=0
#define llcncn llint cnt=0
#define llasas llint ans=0
#define str string
#define please return
#define AC 0
#define ic_a int a;cin>>a;
#define ic_b int b;cin>>b;
#define ic_s string s;cin>>s;
#define Rapid_pleaseAC_fast cin.tie(0);ios::sync_with_stdio(false)
#define Pi 3.1415926535897932384626
#define nine 1000000000
using ll = long long;
using namespace std;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<double> vdou;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbool;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;
typedef long double ld;
const ld eps = 1.0e-12; // 許容される誤差
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

unsigned GetDigit(unsigned num) {
	return std::to_string(num).length();
}

int tow(int n) {//2のn乗
	if (n == 0)return 1;
	int x = tow(n / 2);
	x *= x;
	if (n % 2 == 1)x *= 2;
	return x;//@domino
}

int keta(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10; n /= 10;
	}
	return sum;//Nanashi,tRue,wai
}

/*

 (char)toupper(a[n])=文字列のn文字目を大文字で出力

  pow(a,b)=aのb乗

  */
ld mysqrtl(ld x)
{
	ld a = sqrtl((double)x); // 近似値
	do {
		a = (a + x / a) / 2.0L;
	} while (fabsl(x - a * a) > eps);
	return a;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);

}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

//平方根を求める。sqrtより精度が高い。
//epsを変えて誤差を調整する。
int main(void) {
	Rapid_pleaseAC_fast;
	Bint ans = 0, n = 0, count = 0, sum = 0, near = 1000, old = 0;
	Bint  a, b, mon = 1000, nmon = 0, j = 0, lust = 0;
	Bint  h,k=0;
	int value_to_remove = 0;
	bool check = false, checkb = false;
	string s,t;
	vector<Bint> array;
	vector<llint> hh, ww;
	vector<bool> bo(100001, 0);
	vector<char> kabu(3, ' ');
	cin>>n;
	
	rep(i, n) {
		cin >> a;
		array.push_back(a);
		sum += a;
	}
	rep(i, n) {
		    sum -= array.at(i);
			ans += (array.at(i) * sum )% 1000000007;
			ans = ans % 1000000007;
			
	}
	cout << ans << endl;
	please AC;
}

