#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,g,b;
    int res=0;
    cin>>r>>g>>b;
    res=r*100 + g*10 +b;
    if(res%4==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}