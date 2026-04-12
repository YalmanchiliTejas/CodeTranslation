#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int maxh,n,h0,h,t=1;
    cin>>n;
    cin>>h0;
    maxh=h0;
    n--;
    while(n--)
    {
        cin>>h;
        if(h>=maxh)
        {
            t++;
            maxh=h;
        }
    }
    cout<<t<<endl;
    return 0;
}