#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std ;
const int N = 1e7 + 4;
void FastInputOutput()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
inline ll LLD()
{
    ll ret;
    scanf("%lld", &ret);
    return ret;
}
inline int D()
{
    int ret;
    scanf("%d", &ret);
    return ret;
}
void bin( int x )
{
    if(!x)
        return;
    bin( x / 2 );
    cout << x % 2 ;
}
bool checkPrimeNumber(int n)
{
    bool flag = true;
    for(int j = 2 ; j <= n ; ++j)
    {
        if (n % j == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool cmp(string last, string first)
{
    if(last.size() < first.size())
        return 1;
    return 0;
}
int calculateDigit(int n)
{
    double temp = (double)(n);
    double a = 0.39908-(0.434294 * n);
    double b = log10( n ) ;
    double c = ( n + 0.5 ) * b ;
    double ans = c - abs( a ) ;
    return ceil(ans) ;
}
int findDigits(int n)
{
    double E = 2.71828182845904523536;
    double PI = 3.141592654;

     if (n < 0)
        return 0;
    if (n <= 1)
        return 1;

    double x = ((n * log10(n / E) +
                 log10(2.0 * PI * n) /
                 2.0));

    return floor(x) + 1;
}
ll fact(int n){
ll ans = 1 ;
for(int i = 1 ; i <= n ; ++i)
    ans *= i ;
return ans ;
}
int main()
{
    FastInputOutput() ;
    int n ;
    cin >> n ;
    ll ans = n * 800 ;
    ll t = n / 15 ;
    t *= 200 ;
    cout << ans - t << endl ;

}
