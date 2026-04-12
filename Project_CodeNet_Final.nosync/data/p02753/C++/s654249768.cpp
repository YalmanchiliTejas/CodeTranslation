#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,cnt=0,c=0;
    for(i=0; i<3; i++)
    {
        if(s[i]=='A')
        {
            cnt++;
        }
        if(s[i]=='B') c++;
    }
    if(cnt==0 || c==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
