#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j,a,cnt=0;
    string ch;
    cin>>ch;
    a=ch.size();
    for(i=0;i<a;i++)
    {
        if((ch[i]=='A' && ch[i+1]=='B')|| (ch[i]=='B'&& ch[i+1]=='A'))
        {
            cnt++;
        }

    }
    if(cnt>=1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
