#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
const ll mod = 1000000007;//998244353;
ll nC2(ll n){
    return n*(n-1)/2;
}
ll nC3(ll n){
    return n*(n-1)*(n-2)/6;
}
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string n; cin >> n;
    int k; cin >> k;
    ll ans = 0;
    while(k > 0){
        if (k==1){
            ans += (n[0]-'0')+9*(n.size()-1);
        }
        else if (k==2){
            ans += (n[0]-'0'-1)*(n.size()-1)*9+nC2(n.size()-1)*81;
            n.erase(n.begin());
            while(!n.empty()&&n[0]=='0'){
                n.erase(n.begin());
            }
        }
        else{
            ans += (n[0]-'0'-1)*nC2(n.size()-1)*81+nC3(n.size()-1)*729;
            n.erase(n.begin());;
            while(!n.empty()&&n[0]=='0'){
                n.erase(n.begin());
            }
        }
        k = min(k-1,int(n.size()));
    }
    cout << ans << endl;
}