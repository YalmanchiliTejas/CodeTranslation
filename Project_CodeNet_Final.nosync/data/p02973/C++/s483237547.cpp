#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
#define vecout(V) for(int i=0;i<V.size();i++) {cout<<V[i]<<endl;}

ll INF=1e15;

int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    vector<ll> max_vec;
    rep(i, n){
        auto itr = lower_bound(max_vec.rbegin(), max_vec.rend(), v[i]);//lower_boundは配列の要素のポインタを返す関数
        if (itr == max_vec.rbegin()) {
            max_vec.push_back(v[i]);
        } else {
            --itr;
            *itr = v[i];
        }
    }
    int ans=max_vec.size();
    cout<<ans<<endl;
    return 0;
}