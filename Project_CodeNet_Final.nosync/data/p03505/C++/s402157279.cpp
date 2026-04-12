#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
    cin>>a>>b>>c;
    if(b>=a)
    {
        cout<<1<<endl;
        return 0;
    }
    if(c>=b)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<((a-b)/(b-c)+((a-b)%(b-c)>=1))*2+1<<endl;
    return 0;
}