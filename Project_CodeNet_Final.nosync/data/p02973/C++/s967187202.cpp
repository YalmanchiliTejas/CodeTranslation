#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define END(x) do{cout<<(x)<<endl;exit(0);}while(0)
#define debug(x)  do{cerr<<#x<<": "<<x<<"\n";}while(0)
#define debugv(x) do{cerr<<#x<<": ";for(auto&e: (x))cerr<<e<<" ";cerr<<"\n";}while(0)
#define exp2(x)  (1LL<<(x))
#define cond(a,b,c) ((a)?(b):(c))
using ll=long long;
using namespace std;

int A[100*1000+100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    rep(i, 1, N) cin >> A[i];
    multiset<int> s;
    s.insert(A[1]);
    int ans = 1;

    rep(i, 2, N) {
        auto itlow = s.lower_bound(A[i]);
        while((itlow == s.end() or *itlow >= A[i]) and itlow!=s.begin()) itlow--;
        if (*itlow < A[i]) { s.erase(itlow); } else { ans++; }
        s.insert(A[i]);
    }

    END(ans);
}
