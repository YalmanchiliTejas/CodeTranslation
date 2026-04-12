#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag_a=0,flag_b=0;
    string str;
    cin>>str;
    for(int i=0; str[i]; i++)
    {
        if(str[i]=='A')
        {
            flag_a=1;
        }
        else if(str[i]=='B')
        {
            flag_b=1;
        }
        if(flag_a&&flag_b)
        {
            break;
        }
    }
    if(flag_a&&flag_b)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;

    }








    return 0;
}

