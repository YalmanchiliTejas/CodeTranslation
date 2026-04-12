#include<iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, x, y=0;
    cin>>n;
    x=n*800;
    if(n>=15)
        for(int i=15; i<=n; ++i)
            {
                if(i%15==0)
                    y+=200;
                else
                    continue ;
            }

    cout<<x-y;
    return 0;
}