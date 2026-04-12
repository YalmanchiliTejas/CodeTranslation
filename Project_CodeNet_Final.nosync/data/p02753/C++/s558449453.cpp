#include <bits/stdc++.h>
#define fr first
#define se second
#define r_0 return 0
#define ll long long
#define pb push_back
#define TIME ios_base::sync_with_stdio(0);
using namespace std;

const long long INF = 1e7;
const long long N = 1e6 + 7;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;

ll T = 1, n, m, q, ans, a[N], cnt;
string s;
vector < ll > v, v1;
set< char > st;
int main(){
    TIME
    cin >> s;
    for( auto it:s )
        st.insert(it);
    if( st.size() == 1 )
        cout << "No";
    else
        cout << "Yes";
}
