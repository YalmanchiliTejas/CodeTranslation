#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

int main()
{
	int a , b,  c, x,  y;
	cin >> a >> b>>  c>> x>>  y;
	ll ans = INF; ;
	for(int i = 0 ; i <=  max(x,y) ; i++ ){
		//2i個のcを買う
		ll tmp = 0;
		tmp += 2*c * i ;
		tmp += max(0,x-i) * a  + max(0,y-i) * b;
		chmin(ans,tmp);
	}
	cout << ans << endl;
}
