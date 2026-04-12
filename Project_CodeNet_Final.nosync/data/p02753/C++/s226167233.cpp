#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    string s;
    cin >> s;
    bool a = false, b = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A')
            a = true;
        else
            b = true;
    }
    if(a && b)
        cout << "Yes";
    else cout << "No";
    return 0;
}
