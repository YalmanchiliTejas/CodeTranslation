#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll n;
int main(){
    int h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h) cin>>s[i];
    int a[w]={0},b[h]={0};

    for(int i=0;i<w;i++){
        bool ok = true;
        for(int j=0;j<h;j++){
            if(s[j][i]=='#') ok = false;
        }
        if(ok) a[i]=1;
    }

    for(int i=0;i<h;i++){
        bool ok = true;
        for(int j=0;j<w;j++){
            if(s[i][j]=='#') ok = false;
        }
        if(ok) b[i]=1;
    }
    /*
    rep(i,w) cout<<a[i]<<" ";
    cout<<endl;
    rep(i,h) cout<<b[i]<<" ";
    cout<<endl;
    */
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(b[i]==1 || a[j]==1);
            else cout<<s[i][j];
        }
        if(b[i]==0)cout<<endl;
    }
    return 0;
}