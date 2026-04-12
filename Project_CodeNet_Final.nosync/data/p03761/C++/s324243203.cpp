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

//Write From this Line

const int mod = 1e9+7;
int main()
{
	int n ;
	cin >> n ;
	vector<int> a(26,100);
	
	rep(i,n){
		string s;
		cin >> s;
		vector<int> now(26,0);
		rep(j,s.size()){
			int c =s[j] -'a' ;
			now[c] ++ ;
		}
		rep(j,26){
			chmin(a[j],now[j]);
		}
	}
	int ans = 0 ;
	rep(i,26){
		char c = 'a' + i;
		rep(j,a[i]) cout << c ;
	}
	cout << endl;
}
