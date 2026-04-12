#include<bits/stdc++.h>
#define int long long
#define dd second
#define mp make_pair
#define pb push_back
#define ff first
#define dd second
#define pp pair<int,int>
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == 'C' and s[i-1] == 'A')
        {
            cout << "Yes" << endl; exit(0);
        }
    }
    cout << "No" << endl;
}

