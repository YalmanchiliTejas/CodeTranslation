#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t)
    {
        string s;
        cin>>s;
        int n=s.length();
        bool p=false;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                p=true;
                break;
            }
        }
        if(p)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        t--;
    }
    return 0;
}





