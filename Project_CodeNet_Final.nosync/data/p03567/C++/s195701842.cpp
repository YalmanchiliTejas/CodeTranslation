#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A'&&s[i+1]=='C')
            {
                flag=1;
                break;
            }
        }
        flag?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
