#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s;
    set<char> st;
    cin >> s;
    st.insert(s[0]);
    st.insert(s[1]);
    st.insert(s[2]);
    cout << (st.size() == 2 ? "Yes" : "No") << endl;
}