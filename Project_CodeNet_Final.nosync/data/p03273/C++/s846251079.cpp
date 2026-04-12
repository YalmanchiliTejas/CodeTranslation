#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(ll)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    char t[h][w];
    bool ok[h][w];
    rep(i,h)rep(j,w){
        cin>>t[i][j];
        ok[i][j]=true;
    }
    rep(i,h){
        bool jud=true;
        rep(j,w){
            if(t[i][j]=='#'){
                jud=false;
                break;
            }
        }
        if(jud){
            rep(j,w){
                ok[i][j]=false;
            }
        }
    }
    rep(i,w){
        bool jud=true;
        rep(j,h){
            if(t[j][i]=='#'){
                jud=false;
                break;
            }
        }
        if(jud){
            rep(j,h){
                ok[j][i]=false;
            }
        }
    }
    rep(i,h){
        bool jud=false;
        rep(j,w){
            if(ok[i][j]){
                cout<<t[i][j];
                jud=true;
            }
        }
        if(jud)cout<<endl;
    }
}