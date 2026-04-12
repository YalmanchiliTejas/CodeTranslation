#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1234567890


int main(){
    ll i,j;
    int s,t,p,q,M,y;
    cin>>s>>t>>p>>q>>M>>y;
    int z=s^t;
    int ans=y^z;
    cout<<ans<<endl;
    return 0;
}
