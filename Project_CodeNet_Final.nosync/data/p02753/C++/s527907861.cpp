#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[4];
    cin>>s;
    if(s[0]=='A'&&s[1]=='B'&&s[2]=='A')
    {
        printf("Yes");
    }
    else if(s[0]=='A'&&s[1]=='B'&&s[2]=='B')
    {
        printf("Yes");
    }
    else if(s[0]=='B'&&s[1]=='A'&&s[2]=='A')
    {
        printf("Yes");
    }
    else if(s[0]=='A'&&s[1]=='A'&&s[2]=='B')
    {
        printf("Yes");
    }

    else if(s[0]=='B'&&s[1]=='B'&&s[2]=='A')
    {
        printf("Yes");
    }
    else if(s[0]=='B'&&s[1]=='A'&&s[2]=='B')
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    cout<<endl;
    return 0;
}
