#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i<r;i++)
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pb(c) push_back(c)
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define max(a, b) (((a)<(b))?b:a)
#define min(a, b) ((a>b)?b:a)
#define mp(i, j) make_pair(i,j)
#define ull unsigned long long int
#define ll  long long int
#define pi 3.141592653589793238
#define inf ((ll)1e18)
#define eps 1e-14
#define maxlg 18
#define left(i) ((i)<<1)
#define right(i) (((i)<<1)+1)
#define maxn 2006
int a,b;
int d[26][26];
int f[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 #endif
    cin>>a>>b;
    rep (i,0,a)
        rep (j,0,b)
            cin>>d[i+1][j+1];

    rep (i,0,100+1)
        rep (j,0,100+1)
            rep (x,1,a+1)
                rep (y,1,b+1) {
                    f[i][j] = max(f[i][j],d[x][y]-i*x-j*y);
                }

    rep (x,1,a+1)
        rep (y,1,b+1) {
            int dist = 1e9;
            rep (i,0,100+1)
                rep (j,0,100+1) {
                    dist= min(dist,f[i][j]+i*x +j*y);
                }
            if (dist!=d[x][y]){
                cout<<"Impossible";
                return 0;
            }
        }
    cout<<"Possible\n";
    vector<string>  ans;
    rep (i,1,101) {
        ans.push_back(to_string(i)+ " "+to_string(i+1)+ " X\n");
        rep (j,102,203) {
            ans.push_back(to_string(i)+ " "+to_string(j)+" "+ to_string(f[i-1][202-j])+"\n");
        }
    }
    rep (i,102,202) {
        ans.push_back(to_string(i)+ " "+to_string(i+1)+ " Y\n");
    }
    cout<<202<<" "<<ans.size()<<endl;
    rep (i,0,ans.size()) {
        cout<<ans[i];
    }
    cout<<1<<" "<<202;
    return 0;


}