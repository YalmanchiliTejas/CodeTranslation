#include <bits/stdc++.h>
using namespace std;


vector<long long> a(51);

vector<long long> p(51);


long long f(long long x, long long y){

          if( x == 0 ) return 1;

          else if( y == 1 ) return 0;

          else if( y <= 1 + a.at(x - 1) ) return f( x - 1, y - 1 );

          else if( y == 2 + a.at(x - 1) ) return p.at(x - 1) + 1;

          else if( y <= 2 + 2 * a.at(x - 1) ) return 1 + p.at(x - 1) + f( x - 1, y - 2 - a.at(x - 1) );

          else if( y == 3 + 2 * a.at(x - 1) ) return 2 * p.at(x - 1) + 1;

          }


int main(){


    long long n, x, i, k;


    cin >> n >> x;


    a.at(0) = 1;

    p.at(0) = 1;


    for( i = 1 ; i <= n ; i = i + 1 ){

         a.at(i) = 3 + 2 * a.at(i - 1);

         p.at(i) = 1 + 2 * p.at(i - 1);

         }


    k = f(n, x);


    cout << k << endl;

    
    return 0;


    }
