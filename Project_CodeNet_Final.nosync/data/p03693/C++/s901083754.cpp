#include <cstdio>
#include <iostream>
#define INT long long int
using namespace std;
int r, g, b;

int main()
{
    ios::sync_with_stdio(false);
    cin>>r>>g>>b;
    if( (g*10+b)%4 == 0 ) cout<<"YES"<<endl;
    else cout<<"NO\n";
    return 0;
}
