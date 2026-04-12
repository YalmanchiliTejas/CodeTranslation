#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;

    string s;

    bool flag = 0;

    cin>>s;

    for(i=0;i<s.size();i++)
    {
        if(s[i]!=s[0])
        {
            flag = 1;
            break;
        }

        else{

            flag = 0;
        }
    }
    if(flag == 0)
    {
        cout<<"No";
    }
    else{

        cout<<"Yes";
    }

}
