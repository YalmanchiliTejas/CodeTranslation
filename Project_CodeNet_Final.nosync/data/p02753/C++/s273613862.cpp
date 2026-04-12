#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i] == 'A')
        {
            if(s[i+1]=='B')
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        if(s[i]=='B')
        {
            if(s[i+1]=='A')
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
