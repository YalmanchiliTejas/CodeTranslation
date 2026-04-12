#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
const int lgn = 40;
void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    vector<array<ll,lgn>> dp1(m);
    vector<array<int,lgn>> dp2(m);
    for(int i=0;i<m;i++){
        dp1[i][0] = i;
        dp2[i][0] = (ll)i*i%m;
    }
    for(int j=1;j<lgn;j++){
        for(int i=0;i<m;i++){
            dp2[i][j] = dp2[dp2[i][j-1]][j-1];
            dp1[i][j] = dp1[i][j-1] + dp1[dp2[i][j-1]][j-1];
        }
    }
    ll ans = 0;
    while(n){
        int lg = __builtin_ctzll(n);
        n^=(1ll<<lg);
        ans+=dp1[x][lg];
        x = dp2[x][lg];
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}