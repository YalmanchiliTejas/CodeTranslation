#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    char a;
    int counta=0,countb=0;
  for(int i=1;i<=3;i++)
    {
        cin>>a;
        if(a=='A')
            counta++;
        else
            countb++;
    }
    if(counta<3&&countb<3)
        cout<<"Yes"<<endl;
    if(counta==3||countb==3)
        cout<<"No"<<endl;


    return 0;
}





