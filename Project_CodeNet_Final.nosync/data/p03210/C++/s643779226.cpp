#include <iostream>
#include <cstring>
#define und &&
#define oder ||
using namespace std;
int main()
{
    int X;
    while(cin>>X)
    {
        if(X==3 oder X==5 oder X==7)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
