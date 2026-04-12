#include <bits/stdc++.h>
using namespace std;

ifstream in ( "test.in"  );
ofstream out( "test.out" );

deque<int> que;

int main() {
    
    int n;
    cin >> n;
    
    for( int i = 1; i <= n; i ++ ) {
        int x;
        cin >> x;
        
        if( i % 2 == 0 )
            que.push_back( x );
        else
            que.push_front( x );
    }
    
    if( n % 2 == 0 )
        reverse( que.begin(), que.end() );
    
    for( int x : que )
        cout << x << " ";
    
    return 0;
}
