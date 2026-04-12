#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[3];
    int i,count1=0,count2=0,len=0;
    cin>>s;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='A')
        count1++;
        else
        count2++;
    }
    if((count1==3)||(count2==3))
    cout<<"No";
    else
    cout<<"Yes";
}