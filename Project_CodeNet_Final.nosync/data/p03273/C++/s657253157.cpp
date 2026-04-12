#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
 
int main()
{
	int h, w ;
	cin >> h >> w ;
	vector<string> a(h);
	rep(i, h)cin>>a[i];

	map<int,bool> gyou;
	map<int,bool> retu;

	rep(i,h){
		bool check = true;
		rep(j,w){
			if(a[i][j] == '#') check = false;
		}
		if(check){
			gyou[i] = true;
		}
	}
	rep(j,w){
		bool check = true;
		rep(i,h){
			if(a[i][j] == '#') check = false;
		}
		if(check){
			retu[j] = true;
		}
	}

	rep(i,h){
		int count = 0;
		rep(j,w){
			if(gyou[i] || retu[j])continue;
			cout << a[i][j];
			count++;
		}
		if(count != 0){
			cout << endl;
		}
	}
}
