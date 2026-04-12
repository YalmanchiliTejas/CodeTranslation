#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,a,b;
    cin>>x>>a>>b;
    int s=x*100+a*10+b;
    (s%4==0)?cout<<"YES":cout<<"NO";
}
