#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
    string str;
    cin >> str;
    set<char> st;
    for(int i=0; i<str.length(); i++){
        st.insert(str[i]);
    }
    if(st.size() == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
