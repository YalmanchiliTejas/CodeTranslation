#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[7];
    while(cin>>a)
    {
        int flag=0;
        for(int i=0;i<strlen(a)-1;i++)
            if(a[i]=='A'&&a[i+1]=='C')
            {
                flag=1;
            }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}