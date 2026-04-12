#include <iostream>
#include <algorithm>
#include <string>
#include <cmath> //abs();
using namespace std;

int main(void)
{
    long long int a,b,c,d,i,j,k,n,x[10];
    string s;
    char C[5];

    cin >> a >> b >> c;


    if( (b*10+c)%4  ) cout << "NO"; 
    else cout << "YES";
    return 0;
}