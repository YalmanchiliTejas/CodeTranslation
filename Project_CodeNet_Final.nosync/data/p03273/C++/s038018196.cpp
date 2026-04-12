#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define inf 1000000000000000000

using namespace std;

signed main(){
    int h,w;
    cin>>h>>w;
    char a[h][w];
    rep(i,h){
        cin>>a[i];
    }
    set<int> vh;
    rep(i,h){
        bool f=true;
        rep(j,w){
            if(a[i][j]=='#'){
                f=false;
                break;
            }
        }
        if(f)vh.insert(i);
    }
    set<int> vw;
    rep(i,w){
        bool f=true;
        rep(j,h){
            if(a[j][i]=='#'){
                f=false;
                break;
            }
        }
        if(f)vw.insert(i);
    }
    rep(i,h){
        if(vh.find(i)==vh.end()){
            rep(j,w){
                if(vw.find(j)==vw.end()){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}