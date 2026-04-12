#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    string s;
    
    cin >> n;
    cin >> s;
    cin >> k;
    
    for(auto i : s)
    {
        if(i != s[k - 1])
            cout << "*";
        else cout << i;
    }
    
    return 0;
}