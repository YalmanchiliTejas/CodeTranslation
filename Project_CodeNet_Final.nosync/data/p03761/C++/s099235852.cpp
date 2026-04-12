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
signed main(){
    int n;
    cin>>n;
    string s[55];
    int a[55][55];
    memset(a,0,sizeof(a));
    rep(i,0,n){
        cin>>s[i];
        
        rep(j,0,s[i].size()){
            a[i][s[i][j]-'a']++;
        }
    }
    rep(i,0,26){
        int ans=111;
        rep(j,0,n){
            ans=min(ans,a[j][i]);
        }
        if(ans>0){
            rep(h,0,ans){
        cout<<char(i+'a');
            }
        }
    }
    cout<<endl;
    return 0;
}