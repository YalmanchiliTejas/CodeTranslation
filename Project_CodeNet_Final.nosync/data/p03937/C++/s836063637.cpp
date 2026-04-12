// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    ll h,w;
    cin>>h>>w;
    string str[h];
    rep(i,h) cin>>str[i];
    ll x=0;
    ll y=0;
    while(x!=w-1||y!=h-1){
        if(y!=h-1&&str[y+1][x]=='#'){
            str[y+1][x]='.';
            y++;
        }else if(x!=w-1&&str[y][x+1]=='#'){
            str[y][x+1]='.';
            x++;
        }else{
            f=1;
            break;
        }
       // cout<<y<<" "<<x<<endl;
    }
   // cout<<str[1][4]<<endl;
  //  rep(i,h){rep(j,w) {cout<<str[i][j];}ln;}
    if(str[0][0]=='.') f=1;
    str[0][0]='.';
    str[h-1][w-1]='.';
    rep(i,h)rep(j,w) if(str[i][j]=='#') f=1;
    if(f)cout<<"Impossible"<<endl;
    else cout<<"Possible"<<endl;
    
    return 0;
}
