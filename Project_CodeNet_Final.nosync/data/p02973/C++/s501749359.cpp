#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    int n;cin >>n;
    multiset<int>s;
    V a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    s.insert(-INF);
    for (int i = 0; i < n; ++i) {
        auto it=s.lower_bound(a[i]);
        it--;
        if(*it==-INF)s.insert(a[i]);
        else {
            s.insert(a[i]);
            s.erase(it);
        }
    }
    cout <<s.size()-1<<endl;
}
