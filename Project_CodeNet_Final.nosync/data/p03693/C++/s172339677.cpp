#include <iostream>

using namespace std;

int main()
{
    int r ,g ,b ;
    cin >> r >> g >> b ;
    int a = g*10+b;
    if(!(a%4))cout << "YES";
    else cout << "NO";
    return 0;
}
