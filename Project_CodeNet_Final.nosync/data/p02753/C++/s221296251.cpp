#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
signed main()
{
    SPEED;
    string str;
    cin>>str;
    int ca=0,cb=0;
    for(int i=0;i<3;i++)
    {
        if(str[i]=='A')
        {
            ca++;
        }
        else
        {
            cb++;
        }
    }
    if(ca==0 || cb==0)
    {
        cout<<"No";
    }
    else
    cout<<"Yes";
}