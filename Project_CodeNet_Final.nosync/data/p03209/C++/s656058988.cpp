#include<iostream>
#include<vector>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
using ll = long long;
using P = pair<ll,ll>;
vector<ll> a,p;
ll dfs(ll n,ll x){
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }
    else if(x <= 1 + a[n - 1]) return dfs(n - 1, x - 1);
    else return p[n - 1] + 1 + dfs(n - 1, x - 2 - a[n - 1]);
}
int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
ll n,m;
cin >> n >> m;
a.assign(1,1);
p.assign(1,1);
rep(i,n){
    a.emplace_back(a[i] * 2 + 3);
    p.emplace_back(p[i] * 2 + 1);
}
cout << dfs(n,m) << endl;
}