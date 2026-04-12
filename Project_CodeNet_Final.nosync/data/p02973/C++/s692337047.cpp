#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


void solve(long long N, std::vector<long long> A){
    multiset<int> st;
    for(int i = N - 1; i >= 0;  --i) {
        auto it = st.upper_bound(A[i]);

        if (it != st.end()) {
            st.erase(it);
        }
        st.insert(A[i]);
    }
    cout << st.size() << endl;
}

signed main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
