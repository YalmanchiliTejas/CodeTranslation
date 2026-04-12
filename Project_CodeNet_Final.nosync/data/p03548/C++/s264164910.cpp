#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        int a;
        a=(x-z)/(y+z);
        cout<<a<<endl;
    }
    return 0;
}
