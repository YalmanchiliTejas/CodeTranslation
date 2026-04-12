#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,x=0,y=0;
    cin>>a;
    x=a*800;
    for(int i=0;i<a/15;i++)
    {
        y++;
    }
    cout<<x-y*200<<endl;
    return 0;
}
