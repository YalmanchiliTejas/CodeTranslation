#include <bits/stdc++.h>

using namespace std ;

#define sz(v) (int)v.size()
#define ll long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pf push_front
#define pb push_back
#define fast FastInputOutput() ;
#define Clear( container , value ) memset( container , value , sizeof container )
#define PI acos( -1.0 )
#define forn( t , v , be , n ) for( t v = be ; v < n ; v++ )
#define fore( x , j ) for( auto x : j )
#define se second
#define fr first
//#define c_b fflush(stdin);

const ll Long_max = numeric_limits < ll > :: max() ;
const int Int_max = numeric_limits < int > :: max() ;

void File_input( string pathIn ) {
    freopen( pathIn.c_str(), "r", stdin ) ;
}

void File_output( string pathOut ) {
    freopen( pathOut.c_str(), "w", stdout ) ;
}

int msg() {
    srand( time( 0 ) ) ;
    vector < string > st = {
        "Wish everyone high ratings!",
        "Good luck!",
        "Have fun!",
        "Please, read all the problems!",
        "Go Go fight!"
    } ;
    cerr << st[ rand() % sz( st ) ] ;
    return 0 ;
}

void FastInputOutput() {
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}

const int N = 200 ;
vector < int > adj[ N ] ;
int n , m ;
vector < bool > vis( N ) ;
int cn = 0 ;
set < int > in ;

void DFS( int u , int frq[] , int c ){
  vis[ u ] = 1;
  if( frq[ u ] + 1 >= 2 ) return ;
  frq[ u ]++ ;
    fore( i , adj[ u ] ){
       if( !vis[ i ] ){
         vis[ i ] = 1 ;
         DFS( i , frq , c + 1 ) ;
       }
       vis[ i ] = 0 ;
    }
  if( c == sz( in ) ) cn++ ;
  frq[ u ]-- ;
}

int main() {
    cin >> n >> m ;
    int a , b ;
    while( m-- ){
        cin >> a >> b ;
        adj[ a ].pb( b ) ;
        adj[ b ].pb( a ) ;
        in.insert( a ) ;
        in.insert( b ) ;
    }

    int frq[ N ] = { 0 } ;
    DFS( 1 , frq , 1 ) ;
    cout << cn ;

    return 0 ;
}

