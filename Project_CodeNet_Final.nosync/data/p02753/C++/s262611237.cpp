#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(a,j,n) for(ll i=a;i<j;i=i+n )
typedef pair<ll,ll> P;
const ll mod = 1000000007;
const ll INF = 1000000009;
ll i;

int main(){
    string s;
    cin>>s;
    set<char> c;
    rep(0,3,1){
        c.insert(s.at(i));
    }
    if(c.size()==1)cout<<"No";
    else cout<<"Yes";
    cout<<endl;
}
