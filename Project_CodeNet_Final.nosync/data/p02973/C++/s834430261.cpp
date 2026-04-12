#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    multiset<ll> s;
    rep(i,0,n){
        ll a;
        cin>>a;
        auto ite=s.lower_bound(a);
        if(ite!=s.begin()){ite--;s.erase(ite);}
        s.insert(a);
    }
    cout<<s.size()<<endl;

}
    







