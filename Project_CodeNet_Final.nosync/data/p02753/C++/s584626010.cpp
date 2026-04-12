// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //int t = 1; cin >> t; while(t--)
    {
        string s;
        cin >> s;
        if(s[0] == s[1] && s[1] == s[2])
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

