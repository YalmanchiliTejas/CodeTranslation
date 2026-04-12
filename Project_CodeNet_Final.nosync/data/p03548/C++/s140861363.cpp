#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long r,t,y;
    cin>>r>>t>>y;
    r-=y;
    long long f=r/(t+y);
    cout<<f<<endl;
    return 0;
}