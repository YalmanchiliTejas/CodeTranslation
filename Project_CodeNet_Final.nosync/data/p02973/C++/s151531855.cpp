#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< string, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int N;
int A[112345];
cp2 B[112345];
int C[112345];
int ans = 1;
int idx;

int main(){
    
    cin>>N;
    REP( i, N ) cin>>B[i].fi;
    REP( i, N ) B[i].se = N-i;
    
    sort( B, B+N );
    
    int temp = B[0].fi;
    B[0].fi = 0;
    FOR( i, 1, N ){
        if( B[i].fi != temp ){
            temp = B[i].fi;
        }
        B[i].fi = i;
    }
    REP( i, N ) A[N-B[i].se] = B[i].fi;
    
    
    reverse( A, A+N );
    //REP( i, N ) cout<<A[i]<<endl;
    fill( C, C+N, mod );
    
    REP( i, N ){
        idx = upper_bound( C, C+ans, A[i] )-C;
        C[idx] = A[i];
        ans = max( ans, idx+1 );
    }
    
    cout<<ans<<endl;
    
    return 0;
}

