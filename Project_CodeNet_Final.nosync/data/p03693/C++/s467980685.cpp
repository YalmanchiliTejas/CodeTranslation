#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int a,b,c;

int main()
{
    cin>>a>>b>>c;
    a=a*100+b*10+c;
    if(a%4==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
