#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#define  pb push_back
#define  xx first
#define  yy second
//#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
typedef vector<string> vi;
typedef pair<int,int> pi;

      ll bigmod ( long long a, int p, int m )
{
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p & 1 ) // If power is odd
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
        long long tmp = bigmod ( a, p / 2, m );
        return ( tmp * tmp ) % m;
    }
}

int main()
{
         //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
           int t=1,caseno = 0;

   // scanf("%d",&t);

     while(t--){
       string s;cin >> s;
       if(s=="BBB" || s=="AAA"){
        cout << "No" << endl;
       }
       else cout << "Yes" << endl;
    }

    return 0;
}

