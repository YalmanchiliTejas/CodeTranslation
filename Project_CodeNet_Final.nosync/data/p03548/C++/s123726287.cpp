#include <iostream>

using namespace std;
int n;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    int a=y+z;
    int sum=x/a;
    cout<<sum<<endl;

    return 0;
}
