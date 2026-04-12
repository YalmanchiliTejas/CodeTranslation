#include<bits/stdc++.h>
using namespace std;
int main()
{
    char name[101];
    cin>>name;
    int i;
    int k=0,l=0;
    for(i=0;i<strlen(name);i++)
    {
        if(name[i]=='A')
        {
            k++;
        }
        else
        {
            l++;
        }
    }
    if(k>0 && l>0)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}
