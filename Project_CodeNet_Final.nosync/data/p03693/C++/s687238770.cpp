#include"bits/stdc++.h"
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
#define COUT(x) cout<<x<<endl

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double PI = acos(-1.0);
const LL MOD = 1e9 + 7;
const ULL INF = 1e18;
const int dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };

//function
//--------------------------------------------
LL gcd(LL, LL);
bool isEven(LL);
void coutY();
void coutN();
LL ave(LL, LL);
bool isMultiOf(LL, LL);

int main() {
	int a, b, c; cin >> a >> b >> c;
	int ans = b * 10 + c;
	if (isMultiOf(ans, 4)) {
		cout << "YES";
	}
	else cout << "NO";
}

LL gcd(LL a, LL b) {
	if (a == 0 || b == 0)return 0;
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	else gcd(b, a % b);
}
bool isEven(LL a) {
	return !((bool)(a % 2));
}
void coutY() {
	cout << "Yes" << endl;
	return;
}
void coutN() {
	cout << "No" << endl;
	return;
}
LL ave(LL a, LL b) {
	return (a + b) / 2;
}
bool isMultiOf(LL a, LL b) {
	return a % b == 0;
}