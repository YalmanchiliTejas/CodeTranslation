#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i);
    }
    
    multiset<int64_t> st = {A[0]};
    for ( int64_t i = 1; i < N; ++i){
        int64_t min = *st.begin();
        if ( A[i] <= min ) {
            st.insert(A[i]);
        } else {
            auto itr = st.lower_bound(A[i]);
            --itr;
            st.erase(itr);
            st.insert(A[i]);
        }
        /*for ( auto s: st){
            cout << i << " " << s << endl;
        }*/
    }
    cout << st.size() << endl;
    
    return 0;
}
