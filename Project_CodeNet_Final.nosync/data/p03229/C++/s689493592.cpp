#include <bits/stdc++.h>
using namespace std;


int main(){


    long long n, i, t;

    long long k1 = 0;

    long long k2 = 0;

    vector<long long> a;

    vector<long long> b;

 
    cin >> n;


    for( i = 0 ; i < n ; i = i + 1 ){

         cin >> t;

         a.push_back(t);

         b.push_back(t);

         }


    sort( a.rbegin(), a.rend() );

    sort( b.begin(), b.end() );


    for( i = 0 ; 2 * i < n - 2 ; i = i + 1 ){

         k1 += 2 * a.at(i);

         k1 -= 2 * b.at(i);

         k2 += 2 * a.at(i);

         k2 -= 2 * b.at(i);

         }


    if( n % 2 == 0 ){

        k1 -= b.at(n / 2 - 1);

        k1 += a.at(n / 2 - 1);

        k2 -= b.at(n / 2 - 1);

        k2 += a.at(n / 2 - 1);

        }

    else{       

          k1 -= b.at(n / 2);

          k1 += b.at(n / 2 - 1);

          k2 += a.at(n / 2);

          k2 -= a.at(n / 2 - 1);

          }


    cout << max( k1, k2 ) << endl;


    return 0;


    }