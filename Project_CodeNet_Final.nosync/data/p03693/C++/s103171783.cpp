#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main()
{
    cin>>a>>b>>c;
    int rs=100*a+10*b+c;
    if(rs%4==0)
        cout<<"YES";
    else
        cout<<"NO";
}
