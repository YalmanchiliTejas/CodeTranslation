#include<bits/stdc++.h> 
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int i = 0; i < N; i++)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    multiset<int> st;
    st.insert(A[N-1]);
    for(int i = N-2; i >= 0; i--){
        auto it = st.upper_bound(A[i]);
        if(it == st.end()){
            st.insert(A[i]);
            continue;
        }
        if(*it > A[i]) st.erase(it);
        st.insert(A[i]);
    }

    cout << st.size() << endl;
}

