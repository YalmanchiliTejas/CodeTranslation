#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> path(n, vector<bool>(n, false));
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        path[a][b] = true;
        path[b][a] = true;
    }
    vector<int> v(n);
	rep(i,n) v[i] = i;
    int ans = 0;
	do{
		if(v[0] != 0) continue;
        bool ok = true;
        rep(i,n-1){
            if(!path[v[i]][v[i+1]]){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
	} while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}