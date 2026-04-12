#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ct[3];
    int count=0;
    for(int i=0;i<3;i++)
    {
        scanf("%c",&ct[i]);
        if(ct[i]=='A') count++;
    }
    if(count==3||count==0) cout<<"No";
    else cout<<"Yes";
}
