#include<bits/stdc++.h>
using namespace std;
long long a,b,c,temp;
int main()
{
    cin>>a>>b>>c;
    if(b>=a)//特判 
    {
        cout<<1<<endl;
        return 0;
    }
    if(c>=b)
    {
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>=1)
	temp=1;
    cout<<((a-b)/(b-c)+temp)*2+1<<endl;
    return 0; 
}