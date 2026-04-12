#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,x;
ll Pnum[55],Bnum[55],num[55];
ll solve(ll level, ll k) {
    if(level == 0) {
        return Pnum[0];
    }
    ll ans = 0;
    k--;//第一个面包
    if(k > num[level-1]) {
        k-=num[level-1];
        ans += Pnum[level-1];
        if(k>0) {
            k--;
            ans++;
        }
        if(k > num[level-1]) {
            k -= num[level-1];
            ans += Pnum[level-1];
            return ans;
        }
    }
    if(k>0)
        ans += solve(level-1,k);
    return ans;
}

int main() {
    cin>>n>>x;
    Pnum[0] = 1;
    num[0] = 1;
    for(int i=1;i<=50;++i) {
        Pnum[i] = Pnum[i-1] * 2 + 1;
        Bnum[i] = Bnum[i-1] * 2 + 2;
        num[i] = Pnum[i] + Bnum[i];
    }
    //cout<<Pnum[2]<<" "<<Bnum[2]<<endl;
    cout<<solve(n,x)<<endl;
}