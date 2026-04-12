#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
char a[4];int x,y;
int main()
{

    cin>>a;
    for(int i=0;i<3;i++)
    {
        if(a[i]=='A')
        {
            x++;
        }
        if(a[i]=='B')
        {
            y++;
        }
    }
    if(x&&y)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
         cout<<"No"<<endl;
    }
    return 0;
}

