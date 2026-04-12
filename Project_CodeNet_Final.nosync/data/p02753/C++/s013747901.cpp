#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count = 0,dount=0;
    string s;
    cin>>s;
    char ch = 'A';
    for(int i = 0; i<3; i++)
    {
        if(s[i]==ch)
            count++;
        else
            dount++;
    }
    if((count == 2 && dount == 1)||(count ==1 && dount ==2))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;

}
