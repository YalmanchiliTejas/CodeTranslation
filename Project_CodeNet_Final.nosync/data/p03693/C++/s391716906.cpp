#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b,c,z;
    scanf("%d %d %d",&a,&b,&c);
    z=a*100+b*10+c;
    if(z%4)cout <<"NO\n";
    else cout << "YES\n";
    return 0;
}