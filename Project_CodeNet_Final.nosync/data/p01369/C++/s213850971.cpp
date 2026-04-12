#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
set<char> st;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    st.insert('q');
    st.insert('w');
    st.insert('e');
    st.insert('r');
    st.insert('t');
    st.insert('a');
    st.insert('s');
    st.insert('d');
    st.insert('f');
    st.insert('g');
    st.insert('z');
    st.insert('x');
    st.insert('c');
    st.insert('v');
    st.insert('b');
    while(true) {
        string S;
        cin >> S;
        if(S == "#") break;
        int ans = 0;
        for(int i = 1; i < S.size(); i++) {
            if((st.find(S[i-1]) == st.end()) ^ (st.find(S[i]) == st.end())) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
