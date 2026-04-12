#include<iostream>
#include<string>
using namespace std;
int main()
{
    int c=0,m=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            c++;
        }
        else if(s[i]=='B')
        {
            m++;
        }
    }
    if(m!=0 && c!=0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
