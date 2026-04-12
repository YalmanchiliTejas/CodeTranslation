#include <bits/stdc++.h>
#define REP(i,n) for ( int i=0; i<int(n); i++ )
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> a;
    REP(i,n) {
        int x;
        cin >> x;
        if ( i%2==0 ) a.push_back(x);
        else a.push_front(x);
    }
    if ( n%2 ) {
        while ( a.size() ) {
            cout << a.back() << " ";
            a.pop_back();
        }
    } else {
        while ( a.size() ) {
            cout << a.front() << " ";
            a.pop_front();
        }
    }
    cout << '\n';
    return 0;
}