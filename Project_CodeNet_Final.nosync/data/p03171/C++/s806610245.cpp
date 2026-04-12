#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define d double
#define INF INT_MAX
#define output for(int i=0;i<sizex;i++) { for(int j=0;j<sizey;j++) { cout << moveChart[i][j] << " "; }cout<<endl; }cout<<endl;

int n;
int arr[3001];
ll dp[3][3001][3001];

inline int otherPlayer( int x ){
    if( x == 1 ) return 2;
                 return 1;
}

ll solve( int player, int L, int R ){

    if( L == R ){
        if( player == 1 ) return  arr[L];
                          return -arr[L];
    }

    if( dp[player][L][R] != -1 ) return dp[player][L][R];

    ll res;
    ll res1, res2;
    if( player == 1 ){
        res1 = solve( otherPlayer(player), L+1, R ) + arr[L];
        res2 = solve( otherPlayer(player), L, R-1 ) + arr[R];
        res = max( res1, res2 );
    }else{
        res1 = solve( otherPlayer(player), L+1, R ) - arr[L];
        res2 = solve( otherPlayer(player), L, R-1 ) - arr[R];
        res = min( res1, res2 );
    }

    return dp[player][L][R] = res;

}

int main() { ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    memset( dp, -1, sizeof dp ); 

    cin >> n; for(int i=0;i<n;i++) cin >> arr[i];

    ll res = solve( 1, 0, n-1 );
    cout << res << endl;

}