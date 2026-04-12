#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=0;;++i)
    {
        if(y*i+z*(i+1)>x)
        {
            if(i==0)
            {
                cout <<0<<endl;
                return 0;
            }
            cout<<i-1<<endl;
            return 0;
        }
    }
    return 0;
}
