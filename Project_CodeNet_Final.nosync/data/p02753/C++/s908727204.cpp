#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b,c,i,j,a=0;
    string s;
    cin>>s;
    for(i=1; i<s.size(); i++)
    {
        if(s[i]!=s[i-1])
        {
            a=1;
            break;
        }
    }
    if(a)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
