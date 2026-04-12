#include <iostream>
using namespace std;
int main()
{
    int x,y,z,a,b,c;
    while(cin>>x>>y>>z){
        a=y+z;b=x%a;c=x/a;
        if(b<z) c--;
        cout<<c<<endl;
    }
    return 0;
}
