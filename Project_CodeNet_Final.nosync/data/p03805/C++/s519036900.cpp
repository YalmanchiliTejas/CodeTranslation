#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<ll,ll>;
using vv = vector<vector<ll>>;
template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;
const long long mod = 1000000007;

int main(void){
    int n,m;cin >> n >>m;
    vector<vector<int>> a(n);
    for(int i=0;i<m;i++){
	int c,d; cin >> c >> d;
	c--;d--;
	a[c].push_back(d);
	a[d].push_back(c);
    }
    vector<int> per(n);
    rep(i,n) per[i] = i;
    int ans=0;
    do{
	bool ok = true;
	if(per[0] != 0) ok = false;
	for(int i=0;i<n-1;i++){
	    bool ok2 = false;
	    for(int j=0;j<a[per[i]].size();j++){
		if(a[per[i]][j]==per[i+1]) ok2 = true;
	    }
	    if(ok2==false){ 
		ok = false;
		break;
	    }
	}    
	if(ok) ans++;
    }while( next_permutation(per.begin(),per.end()) );
    cout << ans << endl;
    return 0;
}
