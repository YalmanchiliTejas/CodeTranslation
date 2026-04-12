/*------------------------- Bism Allah Alruhmin Alrahim -------------------------------*/
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define ford(i, n) for (int i = n - 1; i > -1; i--)
#define forl(i, l, r) for (int i = l; i <= r; i++)
#define vc vector
#define f first
#define s second
#define pb(i) push_back(i)
#define mx(ar, n) (*max_element(ar, ar + n))
#define mn(ar, n) (*min_element(ar, ar + n))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;


int main()
{
    int a, b , c = 1 ;
    int n ;
    cin >> n ; 
    cin >> a; 
    for (int i = 0; i < n-1; i++)
    {
        int x ; cin >> x; 
        if(x>=a){
            c++;
            a = x ;
        }
    }
    cout << c << endl ;
    return 0 ;
}