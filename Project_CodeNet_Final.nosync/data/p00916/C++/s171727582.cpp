#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};



int main(){
    int n;
    while(cin >> n,n){
        vector<int> l(n),t(n),r(n),b(n);
        vector<int> x,y;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            x.pb(l[i]),x.pb(r[i]);
            y.pb(b[i]),y.pb(t[i]);
        }
        sort(ALL(x));x.erase(unique(ALL(x)),x.end());
        sort(ALL(y));y.erase(unique(ALL(y)),y.end());
        int w = 2*(2*n+2),h = 2*(2*n+2);
        vector<vector<int>> v(h,vector<int> (w,0));
        for (int i = 0; i < n; i++) {
            l[i] = 2*(lower_bound(ALL(x),l[i]) - x.begin() + 1);
            r[i] = 2*(lower_bound(ALL(x),r[i]) - x.begin() + 1);
            t[i] = 2*(lower_bound(ALL(y),t[i]) - y.begin() + 1);
            b[i] = 2*(lower_bound(ALL(y),b[i]) - y.begin() + 1);
            for (int j = l[i]; j <= r[i]; j++) {
                v[t[i]][j] = -1;
                v[b[i]][j] = -1;
            }
            for (int j = b[i]; j <= t[i]; j++) {
                v[j][l[i]] = -1;
                v[j][r[i]] = -1;
            }
        }
        queue<P> q;
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(v[i][j]!=0) continue;
                q.push(mp(i,j));
                while(!q.empty()){
                    int a = q.front().first, b = q.front().second;
                    q.pop();
                    if(v[a][b]) continue;
                    v[a][b] = 1;
                    for (int k = 0; k < 4; k++) {
                        int nx = b + dx[k], ny = a + dy[k];
                        if(0<=nx&&nx<w&&0<=ny&&ny<h){
                            if(!v[ny][nx]){
                                q.push(mp(ny,nx));
                            }
                        }
                    }
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

