#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    if ( m > n ) {cout << "No" <<endl;   return 0 ; }
    if ( n == m ){ cout << "Yes"<<endl;    return 0 ;}
    else {cout << "No" <<endl; }
    return 0;
}
