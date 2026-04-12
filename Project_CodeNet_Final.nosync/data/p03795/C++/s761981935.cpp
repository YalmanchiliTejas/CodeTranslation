#include<bits/stdc++.h>
using namespace std;                                        
int main()
{
	int n,x,y;
    cin>>n;
    x=n*800;
    for(int i=1;i<=n/15;i++)
    {
        y++;
    }
    y=y*200;
    cout<<x-y;
    return 0;
} 