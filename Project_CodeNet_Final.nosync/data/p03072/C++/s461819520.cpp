// All Library
// #include <bits/stdc++.h> // https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h

// C Library
// #include <cassert> // (assert.h) C Diagnostics Library (header)
// #include <cctype> // (ctype.h) Character handling functions (header)
// #include <cerrno> // (errno.h) C Errors (header)
// #include <cfloat> // (float.h) Characteristics of floating-point types (header)
// #include <ciso646> // (iso646.h) ISO 646 Alternative operator spellings (header)
#include <climits> // (limits.h) Sizes of integral types (header)
// #include <clocale> // (locale.h) C localization library (header)
#include <cmath> // (math.h) C numerics library (header)
// #include <csetjmp> // (setjmp.h) Non local jumps (header)
// #include <csignal> // (signal.h) C library to handle signals (header)
// #include <cstdarg> // (stdarg.h) Variable arguments handling (header)
// #include <cstdbool> // (stdbool.h) Boolean type (header)
// #include <cstddef> // (stddef.h) C Standard definitions (header)
// #include <cstdint> // (stdint.h) Integer types (header)
#include <cstdio> // (stdio.h) C library to perform Input/Output operations (header)
// #include <cstdlib> // (stdlib.h) C Standard General Utilities Library (header)
// #include <cstring> // (string.h) C Strings (header)
// #include <ctime> // (time.h) C Time Library (header)
// #include <cuchar> // (uchar.h) Unicode characters (header)
// #include <cwchar> // (wchar.h) Wide characters (header)
// #include <cwctype> // (wctype.h) Wide character type (header)

// Containers
// #include <array> // Array header (header)
// #include <bitset> // Bitset header (header)
#include <deque> // Deque header (header)
// #include <forward_list> // Forward list (header)
// #include <list> // List header (header)
#include <map> // Map header (header)
// #include <queue> // Queue header (header)
#include <set> // Set header (header)
// #include <stack> // Stack header (header)
// #include <unordered_map> //Unordered map header (header)
// #include <unordered_set> // Unordered set header (header)
#include <vector> // Vector header (header)

// Input/Output Stream Library
#include <iostream> // The class relies on a single streambuf object for both the input and output operations.
// #include <fstream> // Input/output stream class to operate on files.
// #include <sstream> //

// Miscellaneous headers
#include <algorithm> // Standard Template Library: Algorithms (library )
// #include <chrono> // Time library (header)
// #include <codecvt> // Unicode conversion facets (header)
// #include <complex> // Complex numbers library (header)
// #include <exception> // Standard exceptions (header)
// #include <functional> // Function objects (header)
// #include <initializer_list> // Initializer list (header)
// #include <iterator> // Iterator definitions (header)
// #include <limits> // Numeric limits (header)
// #include <locale> // Localization library (header)
// #include <memory> //Memory elements (header)
// #include <new> // Dynamic memory (header)
// #include <numeric> // Generalized numeric operations (header)
// #include <random> // Random (header)
// #include <ratio> // Ratio header (header)
// #include <regex> // Regular Expressions (header)
// #include <stdexcept> // Exception classes (header)
#include <string> // Strings (header)
// #include <system_error> // System errors (header)
#include <tuple> // Tuple library (header)
// #include <typeinfo> // Type information (header)
// #include <type_traits> //type_traits (header)
// #include <utility> // Utility components (header)
// #include <valarray> // Library for arrays of numeric values (header)

// Boost
// #include <boost/multiprecision/cpp_int.hpp> // https://boostjp.github.io/tips/multiprec-int.html

// policy-based data structure
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace boost::multiprecision;
// using namespace __gnu_pbds;

#define BEGIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define END return EXIT_SUCCESS
#define rep(I,N) for(auto I=0;I<(N);++I)
#define up(I,A,B) for(auto I=(A);I<=(B);++I)
#define dw(I,A,B) for(auto I=(A);I>=(B);--I)
#define all(C) (C).begin(),(C).end()
#define rall(C) (C).rbegin(),(C).rend()
#define ft first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pf push_front
#define pb push_back
#define pt pop_front
#define pk pop_back
#define lb lower_bound
#define ub upper_bound
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>inline void                             in(T &p){cin>>p;}
template<class T1,class T2>inline void                   in(T1 &p1,T2 &p2){cin>>p1>>p2;}
template<class T1,class T2,class T3>inline void          in(T1 &p1,T2 &p2,T3 &p3){cin>>p1>>p2>>p3;}
template<class T1,class T2,class T3,class T4>inline void in(T1 &p1,T2 &p2,T3 &p3,T4 &p4){cin>>p1>>p2>>p3>>p4;}
template<class T>inline void                             ins(T &p){for_each(all(p),in<decltype(p[0])>);}
template<class T>inline void                             out(T p){cout<<p<<endl;}
template<class T1,class T2>inline void                   out(T1 p1,T2 p2){cout<<p1<<" "<<p2<<endl;}
template<class T1,class T2,class T3>inline void          out(T1 p1,T2 p2,T3 p3){cout<<p1<<" "<<p2<<" "<<p3<<endl;}
template<class T1,class T2,class T3,class T4>inline void out(T1 p1,T2 p2,T3 p3,T4 p4){cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;}
template<class T>inline void                             outs(T p){for_each(all(p),out<decltype(p[0])>);}

inline void solve(void){
  int N;
  in(N);
  vector<int> H(N);
  rep(i,N)in(H[i]);
  int cnt=1;
  dw(i,N-1,1){
    bool is_ok=true;
    for(int j=i-1;j>=0;j--){
      if(H[i]<H[j]){
        is_ok=false;
      }
    }
    if(is_ok)cnt++;
  }
  out(cnt);
}

int main(int argc,char**argv){
  BEGIN;
  solve();
  END;
}
