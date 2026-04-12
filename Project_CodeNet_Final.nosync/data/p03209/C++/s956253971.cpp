#include <bits/stdc++.h>
using namespace std;
using lint = int64_t;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define all(v)    begin(v), end(v)
#define in        []{lint n; cin>>n; return n;}()

lint a_memo[51] = {0};
lint a( lint l ) {
    if( a_memo[l] ) return a_memo[l];
    if( l == 0 ) return 1;
    return a_memo[l] = a(l-1) * 2 + 3;
}

lint p_memo[51] = {0};
lint p( lint l ) {
    if( p_memo[l] ) return p_memo[l];
    if( l == 0 ) return 1;
    return p_memo[l] = p(l-1) * 2 + 1;
}

lint f( lint n, lint x ) {
    if( x == 0 ) return 0;
    if( x == a(n) ) return p(n);
    if( x <= a(n)/2 ) return f(n-1, x-1);
    if( x == a(n)/2 +1) return p(n-1) + 1;
    return p( n-1 ) + 1 + f(n-1, x - a(n) / 2 -1 );
}

int main(){ cin.tie(0); ios::sync_with_stdio(false);
    int N = in; //  ←[1,50]
    lint X = in;//  ←[1, a(N)]
    cout << f(N, X) << "\n";
}
