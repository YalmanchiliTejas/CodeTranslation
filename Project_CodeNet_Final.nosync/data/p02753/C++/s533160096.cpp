#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[3];
    int a=0,b=0;
    for(int i=0;i<3;i++)
    {
        cin>>s[i];
    }
        if((s[0]==s[1]) && (s[0]==s[2]) && (s[2]==s[1]))
           {
               a++;
           }
           else{
            b++;
           }
    if(a>b)
    {
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
    return 0;
}
