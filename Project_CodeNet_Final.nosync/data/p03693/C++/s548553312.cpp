#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n;
    cin>>a>>b>>c;
    n=a*100+b*10+c;
    if(n%4==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
	return 0;
}
