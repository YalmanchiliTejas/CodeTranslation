#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int cnt=0,cnt1=0,i;
    for(i=0;i<3;i++)
    {
        cin>>s[i];
        if(s[i]=='A')
            cnt++;
        else
            cnt1++;
    }
    if(cnt==0||cnt1==0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

}
