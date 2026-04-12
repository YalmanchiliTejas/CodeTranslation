
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c;
    d = a*100;
    e = b * 10;
    f = d + e + c;

    if(f%4==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;

}
