#include <iostream>
using namespace std;

int a,b,c,sum;

int main()
{
    cin>>a>>b>>c;
    sum=a*100+b*10+c;
    if(sum%4) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}