#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n = 3, ck = 0;
    string s;

    cin>>s;

    for(i=1;i<n;i++)
    {
        if(s[0]!=s[i])
        {
            ck = 1;
            break;
        }
    }

    if(ck==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
