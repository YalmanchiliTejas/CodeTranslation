#include <iostream>
using namespace std;
#define L long long
L f(L a,L b)
{
    if(a%b == 0)return a/b;
    else return a/b+1;
}
int main()
{
    L a,b,c;
    cin >> a >> b >> c;
    if(b >= a)cout << 1;
    else if(c >= b)cout << -1;
    else cout << f(a-b,b-c)*2+1;
    return 0;
}
