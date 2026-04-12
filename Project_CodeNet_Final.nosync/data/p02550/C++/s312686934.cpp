#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(long long N, long long X, long long M){
    vector<ll> ans;
    ll A = X;
    set<ll> se;
    map<ll, int> mp;
    while(1){
        if(se.find(A) != se.end() || N == ans.size()){
            break;
        }
       // cout<<A<<endl;
        mp[A] = ans.size();
        ans.push_back(A);
        se.insert(A);
        A = (A * A) % M;
    }
    if(ans.size() == N){
        cout<<accumulate(ans.begin(), ans.end(), 0LL)<<endl;
        return;
    }
    ll s = mp[A];

    ll qqq = 0;
    for(int i = 0;i < min(s, N);i++){
        qqq += ans[i];
    }
    N -= min(s, N);
    ll mid = 0;
    int cnt = 0;
    for(int i = s;i < ans.size();i++){
        mid += ans[i];
        cnt++;
    }
    qqq += (N / cnt) * mid;
    for(int i = 0;i < N%(cnt);i++){
        qqq += ans[i + s];
    }
    cout<<qqq<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    long long M;
    scanf("%lld",&M);
    solve(N, X, M);
    return 0;
}
