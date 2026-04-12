#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

//竸プロは楽しい！！！！！！！！
//AtCoderさんいつもありがとうございます！！！！！！！！
signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    reverse(all(a));

    multiset<int> st;
    st.insert(-1);
    int ans=0;
    rep(i,n){
        auto it=st.upper_bound(a[i]);
        if(it==st.end()){
            ans++;
            st.insert(a[i]);
        }else{
            st.erase(it);
            st.insert(a[i]);
        }
    }
    cout<<ans<<endl;

}