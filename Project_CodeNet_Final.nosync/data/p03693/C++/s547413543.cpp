#include <iostream>
using namespace std;

int main(void)
{
    int a,b,c,num;
    cin >> a >> b >> c;
    num = a * 100 +  b * 10 + c;
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl; 
}