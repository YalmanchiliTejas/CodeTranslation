#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller(char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int H,W;
    cin>>H>>W;
    vector<vc> a(H,vc(W));
    rep(i,H) {
        rep(j,W) {
            cin>>a[i][j];
        }
    }
    vector<vector<bool>> ok(H,vector<bool>(W,true));
    rep(i,W) {
        bool check=true;
        rep(j,H) {
            if(a[j][i]=='#') check=false;
        }
        if(check) {
            rep(j,H) ok[j][i]=false;
        }
        check=true;
    }
    int n=0;
    rep(i,W) {
        if(ok[0][i]==true) n++;
    }
    rep(i,H) {
        bool check=true;
        rep(j,W) {
            if(a[i][j]=='#') check=false;
        }
        if(check) {
            rep(j,W) ok[i][j]=false;
        }
        check=true;
    }
    vc ans;
    rep(i,H) {
        bool check=true;
        rep(j,W) {
            if(ok[i][j]==false) {
                check=false;
                continue;
            }
            char c=a[i][j];
            ans.pb(c);
        }
        check=true;
    }
    rep(i,ans.size()) {
        if(i!=0&&i%n==0) cout<<endl;
        cout<<ans[i];
    }
}