#include<bits/stdc++.h>

using namespace std;

int main()
{
    char x,y;
    cin>>x;
    int i = 1;

    while(i >= 0)
    {
        cin>>y;
        if(x != y)
        {
            break;
        }
        i--;

    }
    if(i >= 0)
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

  
}