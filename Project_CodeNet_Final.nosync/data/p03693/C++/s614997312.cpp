#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    int num=r*100+g*10+b;
    if(num%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
