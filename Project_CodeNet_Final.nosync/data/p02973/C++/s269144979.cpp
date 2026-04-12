#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
#define all(v) (v).begin(),(v).end()
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=100000000000000000;
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

int main(){
int n;
cin>>n;
multiset<int,greater<int>> ans;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    auto ite=ans.upper_bound(a);
    if(ite!=ans.end()) ans.erase(ite);
    ans.insert(a);
}
cout<<ans.size()<<endl;
}