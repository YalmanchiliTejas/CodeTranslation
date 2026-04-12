#include <iostream>

using namespace std;

int main()
{
    int a=0,b=0;
    char s[3];
    cin>>s;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='A')
            a++;
        if(s[i]=='B')
            b++;
    }
    if(a==0||b==0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
