#include<iostream>
using namespace std;
#define yes(n) cout << ((n) ? "Yes" : "No") << endl
int main()
{
    int n,m;
    cin >> n >> m;
    if(n == m)
        yes(true);
    else
    {
        yes(false);
    }
    
}