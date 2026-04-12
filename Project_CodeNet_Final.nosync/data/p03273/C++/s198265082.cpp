#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int dyy[]={0,-1,0,1};
int dxx[]={-1,0,1,0};

/*#define int ll*/


int h,w;
string s[111];
bool can[111];
bool retu[111];

signed main(){
    cin>>h>>w;
    rep(i,0,h){
        cin>>s[i];
    }
    bool x=true;
    rep(i,0,h){
        x=true;
        rep(j,0,w){
            if(s[i][j]=='#')x=false;
            if(s[i][j]=='#')can[j]=true;
        }
        if(x)retu[i]=true;
    }
    rep(i,0,h){
        if(retu[i])continue;
        rep(j,0,w){
            if(!can[j])continue;
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}