#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;

    cin>>x>>y>>z;
    x-=z;
    int i=0,count=0;

    while(1)
    {
        if(x-(y+z)>=0)
        {
            x-=y+z;
            count++;
        }
        else
        {
            break;
        }
    }
    cout<<count<<endl;
}