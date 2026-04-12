#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
#define int long long
#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
template<typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}
signed main(signed argc, char* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int MOD = 1000000007;
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    if(n%2){
        vector<int> m1(n/2+1,0),m2(n/2+1,0),m3(n/2+1,0);
        rep(i,n/2){
                m1[i+1]=m1[i]+a[i*2];
                m2[i+1]=m2[i]+a[i*2+1];
                m3[i+1]=m3[i]+a[i*2+2];
        }
        int ans=LLONG_MIN;
        priority_queue<int> que;
        for(int i=n/2;i>=0;i--){
            que.push((m3[n/2]-m3[i]+m2[i]));
            int it=que.top();
            ans=max(ans,it-m2[i]+m1[i]);
        }
        cout<<ans<<endl;
    }
    else{
        vector<int>m1(n/2+1,0),m2(n/2+1,0);
        rep(i,n/2){
            m1[i+1]=m1[i]+a[i*2];
            m2[i+1]=m2[i]+a[i*2+1];
        }
        int ans=LLONG_MIN;
        rep(i,n/2+1){
            int it=m2[n/2]-m2[i]+m1[i];
            ans=max(ans,it);
        }
        cout<<ans<<endl;
    }
}
