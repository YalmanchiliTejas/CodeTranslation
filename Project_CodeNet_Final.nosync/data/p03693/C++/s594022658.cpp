#include <iostream>

using namespace std;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,s,d;
    cin >> a >> s >> d;
    if( (s*10+d) % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
