#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

void Main(){
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	vi vr, vc;

	rep(i,h) {
		int flag = 0;
		cin >> a[i];
		rep(j,w) {
			if(a[i][j] == '#') {
				flag = 1;
				break;
            }
		}
		if(flag) vr.pb(i);
	}
	
	rep(j,w){
		int flag = 0;
		rep(i,h){
			if(a[i][j] == '#') {
				flag = 1;
				break;
			}
		}
		if(flag) vc.pb(j);
	}
  
	for(auto i : vr) {
		for(auto j : vc){
      		cout << a[i][j];
		}
		cout << endl;
    }
	return;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}