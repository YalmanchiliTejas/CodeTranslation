#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    int x=r*100;
    int y=g*10;
    if((x+y+b)%4==0)
        cout<<"YES";
    else
        cout<<"NO";
}

