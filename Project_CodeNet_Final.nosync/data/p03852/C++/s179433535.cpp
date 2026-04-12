#include <bits/stdc++.h>

#define int long long

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
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

string c;
string x[]={"a","i","u","e","o"};

signed main(){
    cin>>c;
    rep(i,0,5){
        if(x[i]==c){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}