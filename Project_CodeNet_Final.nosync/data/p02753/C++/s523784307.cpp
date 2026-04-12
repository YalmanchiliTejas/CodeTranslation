// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#define _USE_MATH_DEFINES
#include<math.h>

//#include<cmath>

#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>



//#include "Ants.h"
using namespace std;
typedef long long ll;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) cout<<s<<endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)

//typedef pair < int, int> P;
ll gcd(ll a, ll b) {//最大公約数を求める///最大公倍数a*b/gcd(a,b)
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcd(ll a, ll b) {//最小公倍数を求める　b=0のときaを返す
	if (b == 0) return a;
	return (a / gcd(a, b)) * b;
}
vector<int> calc(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}
string S;
bool A=false, B=false;
int main()
{
	cin >> S;
	rep(i, S.size()) {
		if (S[i] == 'A') {
			A = true;
		}
		else {
			B = true;
		}
	}
	if (A && B) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}