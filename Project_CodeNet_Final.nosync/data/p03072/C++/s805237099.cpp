#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using lld=long double;
#define all(c) (c).begin(), (c).end()
#define rep( i, a, n ) for( int i=a; i<n; i++ )
#define repp( i, a, n, p ) for( int i=a; i<n; i+=p )
#define per( i, a, n ) for( int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define acc accumulate

int main () {
    int n;
    cin >> n;
    stack <int> st;
    while ( n-- ) {
        int no;
        cin >> no;
        if ( st.empty() ){ 
            st.push (no);
        }

        else { 
            if ( no >= st.top () ) {
                st.push (no);
            }
        }
    }

    cout << st.size() << endl;
}
