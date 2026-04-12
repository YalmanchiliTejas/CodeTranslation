#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

int main()
{
    vector<char> S(2);
    rep(i, 3) cin >> S[i];

   if( S[0] != S[1] )
   {
       cout << "Yes" << endl;
   }
   else if ( S[1] != S[2] )
   {
       cout << "Yes" << endl;
   }
   else if ( S[0] != S[2] )
   {
       cout << "Yes" << endl;
   }
   else
   {
       cout << "No" << endl;
   }
   
        
    
}

