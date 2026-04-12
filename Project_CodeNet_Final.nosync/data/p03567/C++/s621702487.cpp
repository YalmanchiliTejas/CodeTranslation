#include <iostream>
#include <cstdio>　
using namespace std;

int main()
{
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'&&s[i+1]=='C')
            flag=1;
    }
    if(flag==1)
        printf("Yes\n");
    else printf("No\n");

    return 0;
}
