#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>0 && n<=100 && m>=0 && m<=n)
    {
        if(n==m)
            cout<<"Yes"<<endl;
        else if(n>m)
            cout<<"No"<<endl;
    }

    return 0;

}
