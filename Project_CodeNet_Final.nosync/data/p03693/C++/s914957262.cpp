#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,y;
    cin>>a>>b>>c;
    y=(a*100)+(b*10)+c;
    if(y%4==0)
    {
        cout<<"YES";
    }
    else 
    {
        cout<<"NO";
    }

    return 0;
}
