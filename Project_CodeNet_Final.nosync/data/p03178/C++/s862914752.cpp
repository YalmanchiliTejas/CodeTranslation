/////////////////////////////////////////////////////////////////////////////////
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'               `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//  
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$'                   `$$$$$$$$$$$$$$$$$$$$$$$$$$$$//
//$$$'`$$$$$$$$$$$$$'`$$$$$$!                       !$$$$$$'`$$$$$$$$$$$$$'`$$$//
//$$$$  $$$$$$$$$$$  $$$$$$$                         $$$$$$$  $$$$$$$$$$$  $$$$//
//$$$$. `$' \' \$`  $$$$$$$!       $$        $$      !$$$$$$$  '$/ `/ `$' .$$$$//
//$$$$$. !\  i  i .$$$$$$$$       $$$$      $$$$      $$$$$$$$. i  i  /! .$$$$$//
//$$$$$$   `--`--.$$$$$$$$$        $$        $$       $$$$$$$$$.--'--'   $$$$$$//
//$$$$$$L        `$$$$$^^$$                           $$^^$$$$$'        J$$$$$$//
//$$$$$$$.   .'   ""~   $$$    $.                 .$  $$$   ~""   `.   .$$$$$$$//
//$$$$$$$$.  ;      .e$$$$$!    $$.             .$$  !$$$$$e,      ;  .$$$$$$$$//
//$$$$$$$$$   `.$$$$$$$$$$$$     $$$.         .$$$   $$$$$$$$$$$$.'   $$$$$$$$$//
//$$$$$$$$    .$$$$$$$$$$$$$!     $$`$$$$$$$$'$$    !$$$$$$$$$$$$$.    $$$$$$$$//
//$$$$$$$     $$$$$$$$$$$$$$$$.    $    $$    $   .$$$$$$$$$$$$$$$$     $$$$$$$//
//                                 $    $$    $								   //
//                                 $.   $$   .$								   //
//                                `$        $'								   //
//                                 `$$$$$$$$'								   //
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// Type-Define 
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<char> vc;
typedef std::vector< vector<int> > vii;
typedef std::pair<int, int> pii;

// Hash-Define
#define int long long
#define MOD 1000000007
#define debugStart cerr << "\n[DEBUG START]\n"
#define debugStop cerr << "\n[DEBUG STOP]\n"
#define KHATAM cout << std::endl;
#define set_zero(x) memset(x, 0, sizeof(x));
#define ForPrint(x) std::for_each( begin(x), end(x), []( auto const& el ){ std::cout << el << " ";  } )

//Functions 
template<typename T> auto gcd ( T a, T b ) -> int  { return (b==0)?a:gcd(b,a%b); }


const int inf = 1e18L + 5;
const int mod = 1e9 + 7; 

int mod_add ( int a, int b ) {

    int result = a + b;
    if( result >= mod ) {
        result -= mod; 
    }
    return result;
}
int mod_sub ( int a, int  b ) {
    int result = a - b;
    if ( result < 0 ) {
        result += mod;
    }
    return result;
}

int mod_mul ( int a, int b ) {

    return ( ( a % mod ) * ( b % mod ) ) % mod;
}

int D, size;
int dp[10001][101][2];
int solve ( string const& K , int index, bool less, int multiple ) {
    if ( index == size ) {
        return multiple == 0;
    }
    if ( dp[index][multiple][less] != -1 )
      return dp[index][multiple][less];  
    int answer = 0;
    for ( int i = 0; i < ( less?10:(K[index]-'0') ); ++i ) {
        answer = mod_add( answer, solve(K, index + 1, true, ( multiple + i ) % D) );
    }
    if ( not less ) 
        answer = mod_add( answer, solve(K, index + 1, false, ( K[index] - '0' + multiple) % D) );
    return dp[index][multiple][less] = answer;
}

signed
main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    for ( int testcase = 1; testcase <= T; ++testcase ) {
        for ( int i = 0; i < 10001; ++i ) {
            for ( int j = 0; j < 101; ++j ) for ( int k = 0; k < 2; ++k) 
                dp[i][j][k] = -1;
        }
        string K;
        std::cin >> K;
        std::cin >> D;
        size = K.size();
        std::cout << mod_sub(solve(K, 0, false,  0), 1);
        KHATAM; 
    }
    return 0;
}
