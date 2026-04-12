#include <iostream>

using namespace std;

int main()
{
    int m=800, p =200 , n , t , f , r ;
    cin >> n ;
    r = n/15 ;
    t = n*m ;
    f = t-(200*r) ;
    if (n>15)
    cout << f ;
    else
    cout << t ;


    return 0;
}
