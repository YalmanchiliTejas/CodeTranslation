#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    set<char> st;
    for (char c : S) {
        st.insert(c);
    }
    cout << (st.size() == 2 ? "Yes" : "No") << endl;
}