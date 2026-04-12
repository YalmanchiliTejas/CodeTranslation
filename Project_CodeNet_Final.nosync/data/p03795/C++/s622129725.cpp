#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,y;
    cin>>a;
    if(a<15)
    {
        cout<<a*800;
    }
    else if(a==15)
    {
        cout<<(a*800)-200;
    }
    else if(a>15)
    {
        y=a/15;
        cout<<(a*800)-(y*200);
    }


    return 0;
}
