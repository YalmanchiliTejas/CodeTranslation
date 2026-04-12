#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    multiset<int> st;
    while(N--) {
        int A;
        cin >> A;
        st.insert(A);
        auto itr = st.find(A);
        if(itr != st.begin()) {
            st.erase(--itr);
        }
    }
    cout << st.size() << endl;
    return 0;
}
