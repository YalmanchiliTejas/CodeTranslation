#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    int cnt=0,i,cnt1=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='A')
        {
            cnt++;
        }
        else
        {
            cnt1++;
        }
    }
    if(cnt>2 || cnt1>2)
    {
         cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }

}
