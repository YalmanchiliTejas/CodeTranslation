#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int& x: A) cin >> x;

    multiset<int> st;
    st.insert(A[0]);
    for(int i=1; i<N; i++){
        auto itr = st.lower_bound(A[i]);
        if(itr != st.begin()){
            itr--; st.erase(itr);
        }
        st.insert(A[i]);
    }

    cout << st.size() << endl;
}