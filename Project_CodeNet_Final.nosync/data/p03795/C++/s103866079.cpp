#include <bits/stdc++.h>

using namespace std;

int main()
{   int n,count=0;
    cin>>n;
 int x=800*n;
    for(int i=1;i<=n;i++)
    {
        if(i%15==0)
        {
            count++;
        }
    }
    int y=count*200;

     cout<<x-y<<"\n";
    return 0;
}