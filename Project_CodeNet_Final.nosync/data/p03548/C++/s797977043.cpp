#include <iostream> 
#include <cstdio> 
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    a-=c;
    cout<<a/(b+c)<<endl;
    return 0;
}