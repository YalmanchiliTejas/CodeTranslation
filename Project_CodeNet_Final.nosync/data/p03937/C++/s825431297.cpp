#include <bits/stdc++.h>
#define eps 1e-6
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=(n-1);i!=-1;i--)
#define snc(a,b,c) ((a)?(b):(c))
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define ins insert
#define pi acos(-1.0)
#define pb push_back
using namespace std;

char ban[8][9];
int h,w;

bool filled(vector<string> reached){
    rep(i,h){
        rep(j,w){
            if (reached[i].at(j)!=ban[i][j])
                return false;
        }
    }
    return true;
}

bool dfs(int x,int y,vector<string> reached){
    if (x>=w || y>=h || y<0 || x<0 || ban[y][x]=='.') return false;
    if (ban[y][x]=='#') reached[y].at(x)='#';
    if (x==w-1 && y==h-1){
        if (filled(reached))
            return true;
        else
            return false;
    }
    return (dfs(x+1,y,reached) || dfs(x,y+1,reached));
}
int main(){
    cin >> h >> w;
    rep(i,h) cin>>ban[i];
    vector<string> reached;
    reached.resize(h,"........");
    cout << ((dfs(0,0,reached))?"Possible":"Impossible") << endl;
    return 0;
}
