#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    int x, y;
    
    cin >> n;
    
    x = 800 * n;
    y = 200 * (n / 15);
    
    cout << x - y << "\n";
    
    return 0;
}