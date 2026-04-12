#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    string s;
    cin >> s;
    set<char> st;
    for(auto c: s)st.insert(c);
    cout << (st.size() > 1 ? "Yes" : "No") << endl;

    return 0;
}