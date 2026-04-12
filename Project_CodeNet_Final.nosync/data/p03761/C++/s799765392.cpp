#include <bits/stdc++.h>
using namespace std;

const int DIM = 300;

string str;
int hz[DIM], cnt[DIM];

int main( void ) {
    
    int n;
    cin >> n;
    
    for( int i = 'a'; i <= 'z'; i ++ )
        cnt[i] = numeric_limits<int> :: max();
    
    for( int i = 1; i <= n; i ++ ) {
        cin >> str;
        
        for( int i = 'a'; i <= 'z'; i ++ )
            hz[i] = 0;
        
        for( char ch : str )
            hz[ch] ++;
        
        for( int i = 'a'; i <= 'z'; i ++ )
            cnt[i] = min( cnt[i], hz[i] );
    }
    
    for( int i = 'a'; i <= 'z'; i ++ )
        for( int j = 1; j <= cnt[i]; j ++ )
            cout << (char) i;
            
    return 0;
}