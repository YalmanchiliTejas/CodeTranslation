/**
                  ▄█▀ ▀█▀ ▄▀▄ █▀ █▄█▄█ ▄▀▄ █▀ ▄█▀
                  <⇋⇋⇋⋛∰≓⊂(⌒,_ゝ⌒)⊃≓∰⋛⇋⇋⇋>

            ♔♕♖♗♘♙ ☜❷☞✪ ィℋ६ ≈ ᗫẵℜℵĬŊĞ ✪☜❷☞ ♚♛♜♝♞♟
            ♔♕♖♗♘♙                             ♚♛♜♝♞♟
                      ˙·٠•●♥ Ƹ̵̡Ӝ̵̨̄Ʒ ♥●•٠·˙

**/

#include <bits/stdc++.h>

#define sz(s) s.size()
#define pb emplace_back
#define fr first
#define sc second
#define mk make_pair
#define int long long
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9 + 7;

int n, sum, a[N];
vector < int > b;
main()
{
   cin >> n;
   b.pb(-1);
   for( int i = 1; i <= n; i++ )
      cin >> a[i], b.pb( a[i] );

   sort( all( b ) );
   int m = n / 2;

   for( int i = 1; i <= n; i++ )
   {
      if( a[i] > b[ m ] )
         cout << b[ m ] << endl;
      else
         cout << b[ m + 1 ] << endl;
   }
}
