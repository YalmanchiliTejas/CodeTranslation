#include <iostream>
 
#include <iomanip>
using namespace std;
 
int main() 
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "Yes";
    }
    else if (m<n && m>=0)
    {
        cout<<"No";
    }
}