#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <sys/time.h>
#include <vector>


using namespace std;
#define REP(i,n,m) for( long long int i = (n); i < (m); i++ )
#define REP_(i,n,m) for( long long int i = (n); i <= (m); i++ )
#define CNT(i,n) for( long long int i = (n); i > 0; i-- )
#define CNT_(i,n) for( long long int i = (n); i >= 0; i-- )
#define SKIP(i,n,m) for( long long int i = (n); i < (m) ; i+=2 )
#define ll long long
#define ld long double
#define ft first
#define sd second
#define ALL(a) (a).begin(), (a).end()
#define srt(v) sort( v.begin(), v.end() );
#define sz(v) ( int ) v.size()
#define erase( v, i ) v.erase( v.begin() + i)
#define last(v) v[sz(v)-1]
#define swap( v, i, j ) int buf = v[j]; v[j] = v[i]; v[i] = buf;
#define out(a) printf( " %.16f¥n ", a );
#define vi vector<int>
#define vd vector<double>
#define vl vector<long long>
#define pa pair<int, int>
#define mulM( a, b, c ) a = a * b % c;
#define mp make_pair
#define pb push_back
#define iinp(a) int a; cin >> a;
#define sinp(a) string a; cin >> a;
#define ios() ios_base::sync_with_stdio(0); cin.tie(0);
#define EPS (1e-10)
#define PI 3.14159265358979323846

int MOD=1000000007;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void solve(){
  iinp( x )
  if ( x == 3 || x == 5 || x == 7 ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

signed main() {
    ios()
    solve();
    return 0;
}
