/*its_Rashid*/
#include <bits/stdc++.h>
using namespace std ;

typedef double du ;
typedef string st ;
typedef long long ll ;
typedef long double ld ;
typedef long long int lli ;

#define vi vector <lli>
#define loop(num) for (lli i = 0 ; i < num ; i ++ )
#define loopcin(num , ar ) for (lli i = 0 ; i < num ; i ++ ) {cin >> ar [i] ;}
#define loopcout(num , ar) for (lli i = 0 ; i < num ; i ++ ) {cout << ar [i] << ' '; }
#define looppu(num , ar) for (lli i = 0 ; i < num ;  i++) {lli x ; cin >> x ; ar . push_back (x) ;}
#define loopin(num , ar) for (lli i = 0 ; i < num ;  i++) {lli x ; cin >> x ; ar . insert (x) ;}

#define forr(num1 , num2) for (lli i = num1 ; i < num2 ; i ++ )
#define forrcin(num1 , num2 , ar ) for (lli i = num1 ; i < num2 ; i ++ ) {cin >> ar [i] ;}
#define forrcout(num1 , num2 , ar) for (lli i = num1 ; i < num2 ; i ++ ) {cout << ar [i] << ' '; }

#define D2forrcin(num1_1 , num1_2 , num2_1 , num2_2 , A ) for (lli i = num1_1 ; i < num1_2 ; i ++){ for (lli j = num2_1 ; j < num2_2 ; j++){cin >> A[i][j] ;}}
#define D2forrcout(num1_1 , num1_2 , num2_1 , num2_2 , A ) for (lli i = num1_1 ; i < num1_2 ; i ++){ for (lli j = num2_1 ; j < num2_2 ; j++){cout << A[i][j] << ' ' ;}cout << endl ;}

#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

#define F first
#define S second

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main ()
{
    fastio
    lli num , cnt = 1 , m = 0 ;
    cin >> num ;
    lli a[num] ;
    loopcin(num , a) ;
    m = a[0] ;
    forr(1 , num) {
        if (a[i] >= m){
            cnt ++ ;
            m = a[i] ;
        }
    }

    cout << cnt << endl ;
    return 0 ;
}

/*___________________________________________________________________functions___________________________________________________________________________*/

