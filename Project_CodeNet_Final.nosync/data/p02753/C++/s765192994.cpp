#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll MOD = 1e9 + 7 ;
const double PI = 2 * acos(0.0) ;

int main()
{
    set <char> st ;
    string s ;
    cin >> s ;
    for (int i = 0; i < 3; i++) {
        st.insert(s[i]) ;
    }
    if (st.size() == 1) cout << "No" ;
    else    cout << "Yes" ;
}
