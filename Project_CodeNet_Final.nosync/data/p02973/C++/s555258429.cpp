#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=1e5+10;
ll a[Maxn];
map <ll,ll> mp;
set <ll>   S;
//struct Node{
//    ll a;
//    friend bool operator <(const Node A,const Node B){
//        return A.a>B.a;
//    }
//};
//multiset <Node>  S;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
//    S.insert((Node){1});
//    S.insert((Node){1});
//    auto it=S.begin();
//    cout<<it->a;
//    (it->a);
//    cout<<
//    S.insert((Node){4});
//    S.insert((Node){5});
//    S.insert((Node){7});
//    S.insert((Node){8});
//    auto it=S.lower_bound((Node){0});
//    if(it==S.end()){
//        cout<<121<<endl;
//    }
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)    cin>>a[i];
    S.insert(a[1]);
    mp[a[1]]++;
    for(ll i=2;i<=n;i++) {
        ll temp=a[i];
        auto it=S.lower_bound(temp);
        if(it==S.begin()){
            if(temp!=*it)   S.insert(temp);
            mp[temp]++;
        }else{
            it--;
            if(*it==temp){
                if(it!=S.begin()){
                    it--;
                    ll now=*it;
                    if(mp[now]==1)  S.erase(it);
                    mp[now]--;
                    S.insert(temp);
                    mp[temp]++;
                }else{
                    mp[temp]++;
                }
            }else{
                ll now=*it;
                if(mp[now]==1)  S.erase(it);
                mp[now]--;
                S.insert(temp);
                mp[temp]++;
            }
        }
    }
    ll ans=0;
    for(auto it=S.begin();it!=S.end();it++){
        ll now=*it;
        ans+=mp[now];
    }
    cout<<ans;
    return 0;
}
