#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a.at(i);
	int ans=1;
	for(int i=1;i<n;++i){
		bool flg=true;
		rep(j,i){
			if(a.at(j)>a.at(i)) flg=false;
		}
		if(flg) ans++;
	}
	cout << ans << endl;
}
