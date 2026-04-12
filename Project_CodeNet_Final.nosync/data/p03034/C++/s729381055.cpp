#include <bits/stdc++.h>
using namespace std;

void chmax(int64_t& a, int64_t b){
    a = max(a, b);
}

int main(){
    int N;
    int64_t S[100000];
    cin >> N;
    for(int i=0; i<N; i++) cin >> S[i];

    int64_t ans = 0;
    for(int d=1; d<N-1; d++){
        int64_t res = 0;
        set<int> st;
        int l = 0, r = N-1;
        while(true){
            l += d;
            r -= d;
            if(r <= d) break;
            if(st.count(l)) break;
            st.insert(l);
            if(st.count(r)) break;
            st.insert(r);
            res += S[l] + S[r];
            chmax(ans, res);            
        }
    }
    cout << ans << endl;
    return 0;
}
