#include <bits/stdc++.h>
using namespace std;

const int DIM = 2e5 + 5;

pair<int, int> arr[DIM];
int mn1[DIM], mn2[DIM], mx1[DIM], mx2[DIM];

int main( void ) {
    
    int n;
    cin >> n;
    
    for( int i = 1; i <= n; i ++ ) {
        cin >> arr[i].first >> arr[i].second;
        
        if( arr[i].first > arr[i].second )
            swap( arr[i].first, arr[i].second );
    }
    
    sort( arr + 1, arr + n + 1 );
    
    for( int i = 1; i <= n; i ++ ) {
        if( i == 1 )
            mn1[i] = mx1[i] = arr[i].second;
        else {
            mn1[i] = min( mn1[i - 1], arr[i].second );
            mx1[i] = max( mx1[i - 1], arr[i].second );
        }
    }
    
    for( int i = n; i >= 1; i -- ) {
        if( i == n )
            mn2[i] = mx2[i] = arr[i].second;
        else {
            mn2[i] = min( mn2[i + 1], arr[i].second );
            mx2[i] = max( mx2[i + 1], arr[i].second );
        }
    }
    
    long long ans = 1LL * ( arr[n].first - arr[1].first ) * ( mx1[n] - mn1[n] );
    
    for( int i = 1; i < n; i ++ ) {
        int mi1 = min( arr[1].first, mn2[i + 1] ), ma1 = max( arr[i].first, mx2[i + 1] );
        int mi2 = min( arr[i + 1].first, mn1[i] ), ma2 = max( arr[n].first, mx1[i] );
        
        ans = min( ans, 1LL * ( ma1 - mi1 ) * ( ma2 - mi2 ) );
    }
    
    cout << ans << endl;
    return 0;
}