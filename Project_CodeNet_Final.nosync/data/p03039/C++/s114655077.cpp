#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define y0 qvya13579
#define y1 qvyb24680
#define j0 qvja13579
#define j1 qvjb24680
#define next qvne13579xt
#define prev qvpr13579ev
#define INF 1000000007
#define MOD 1000000007
#define PI acos(-1.0)
#define endl "\n"
#define IOS cin.tie(0);ios::sync_with_stdio(false)
#define M_P make_pair
#define PU_B push_back
#define PU_F push_front
#define PO_B pop_back
#define PO_F pop_front
#define U_B upper_bound
#define L_B lower_bound
#define B_S binary_search
#define PR_Q priority_queue
#define FIR first
#define SEC second
#if __cplusplus < 201103L
#define stoi(argument_string) atoi((argument_string).c_str())
#endif
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP_R(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define FOR(i,m,n) for(int i=((int)(m));i<(int)(n);++i)
#define FOR_R(i,m,n) for(int i=((int)(m)-1);i>=(int)(n);--i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZ(x) ((int)(x).size())
#define COUT(x) cout<<(x)<<endl
#define CIN(x) cin>>(x)
#define CIN2(x,y) cin>>(x)>>(y)
#define CIN3(x,y,z) cin>>(x)>>(y)>>(z)
#define CIN4(x,y,z,w) cin>>(x)>>(y)>>(z)>>(w)
#define SCAND(x) scanf("%d",&(x))
#define SCAND2(x,y) scanf("%d%d",&(x),&(y))
#define SCAND3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define SCAND4(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define SCANLLD(x) scanf("%lld",&(x))
#define SCANLLD2(x,y) scanf("%lld%lld",&(x),&(y))
#define SCANLLD3(x,y,z) scanf("%lld%lld%lld",&(x),&(y),&(z))
#define SCANLLD4(x,y,z,w) scanf("%lld%lld%lld%lld",&(x),&(y),&(z),&(w))
#define PRINTD(x) printf("%d\n",(x))
#define PRINTLLD(x) printf("%lld\n",(x))
typedef long long int lli;
using namespace std;


bool compare_by_2nd(pair<int,int> a, pair<int,int> b)
{
  if( a.second != b.second )
    {
      return a.second < b.second;
    }
  else
    {
      return a.first < b.first;
    }
  
}

int ctoi(char c)
{
  if( c >= '0' and c <= '9' )
    {
      return (int)(c-'0');
    }

  return -1;
}

int alphabet_pos(char c) 
{
  if( c >= 'a' and c <= 'z' )
    {
      return (int)(c-'a');
    }

  return -1;
}


int alphabet_pos_capital(char c)
{
  if( c >= 'A' and c <= 'Z' )
    {
      return (int)(c-'A');
    }

  return -1;
}


vector<string> split(string str, char ch)
{
  int first = 0;
  int last = str.find_first_of(ch);
  
  if(last == string::npos)
    {
      last = SIZ(str);
    }

  vector<string> result;

  while( first < SIZ(str) )
    {
      string Ssubstr(str, first, last - first);
      result.push_back(Ssubstr);
      first = last + 1;
      last = str.find_first_of(ch, first);

      if(last == string::npos)
	{
	  last = SIZ(str);
	}
    }
  
  return result;
}



int gcd( int a , int b ) // assuming a,b >= 1
{
  if( a < b )
    {
      return gcd( b , a );
      
    }

  if( a % b == 0 )
    {
      return b;
      
    }

  return gcd( b , a % b );
  
}

int lcm( int a , int b ) // assuming a,b >= 1
{
  return  a * b / gcd( a , b );
  
}

lli pow_fast( lli x, lli n_power , lli modulus )
{
  
  if( n_power == 0 )
    {
      return 1;
    }
  
  if( n_power % 2 == 0)
    {
      return pow_fast( x * x % modulus , n_power / 2 , modulus );  
    }

  
  return x * pow_fast( x , n_power - 1 , modulus ) % modulus;
}


struct UnionFind //size-based
{
  vector<int> parent, treesize;
  
  UnionFind( int size ) : parent( size ) , treesize( size , 1 ) //constructor
  {
    for( int i = 0 ; i < size ; ++ i )
      {
	parent[i] = i;
      }
  }

  int root( int x )
  {
    if( parent[x] == x )
      {
	return x;
      }
    
    return parent[x] = root(parent[x]);
  }

  void unite( int x, int y )
  {
    x = root(x); 
    y = root(y);
    
    if( x == y )
      {
	return; 
      }

    if( treesize[x] < treesize[y] )
      {
	parent[x] = y;
	treesize[y] += treesize[x];
      }
    else
      {
	parent[y] = x;
	treesize[x] += treesize[y];	
      }
    
  }

  bool sametree( int x, int y )
  {
    return root(x) == root(y);
  }

  int gettreesize( int x )
  {
    return treesize[root(x)];
  }
  
};



/*------------------ the end of the template -----------------------*/


lli fac( lli N )
{
  lli cnt = 1;

  while( N > 1 )
    {
      cnt *= N;
      cnt %= MOD;
      -- N;
    }

  return cnt;
}






int main()
{
  IOS; /* making cin faster */
  lli N,M,K;
  SCANLLD3(N,M,K);

  lli comb = fac(N*M-2);
  comb *= pow_fast( fac(K-2) , MOD-2 , MOD );
  comb %= MOD;
  comb *= pow_fast( fac(N*M-K) , MOD-2 , MOD );
  comb %= MOD;

  lli c1 = comb;
  lli c2 = comb;

  c1 *= M;
  c1 %= MOD;
  c1 *= M;
  c1 %= MOD;
  c1 *= N;
  c1 %= MOD;
  c1 *= (N+1);
  c1 %= MOD;
  c1 *= (N-1);
  c1 %= MOD;
  c1 *= pow_fast( 6 , MOD-2 , MOD);
  c1 %= MOD;


  c2 *= N;
  c2 %= MOD;
  c2 *= N;
  c2 %= MOD;
  c2 *= M;
  c2 %= MOD;
  c2 *= (M+1);
  c2 %= MOD;
  c2 *= (M-1);
  c2 %= MOD;
  c2 *= pow_fast( 6 , MOD-2 , MOD);
  c2 %= MOD;

  PRINTLLD((c1+c2)%MOD);
  
  
  
  
  
  

}
