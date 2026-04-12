#include <iostream>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    if ( n<15)
    {
        cout<<n*800;
    }
    else if (n==15) 
    {cout<<(n*800)-200;
    }
    else if(n>15)
    {
        x=n/15;
        cout<<(n*800)-(x*200);
    }
    return 0;
}