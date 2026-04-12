#include<iostream>
using namespace std;
int main()
{
    int n,x,y;
    cin >> n;
    x = n * 800;
    y = 200 * int(n / 15);
    
    cout << (x-y) << endl;
    return 0;
}