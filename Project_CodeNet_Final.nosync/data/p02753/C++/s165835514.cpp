#include<bits/stdc++.h>
using namespace std;
string s;
int cnta;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'||s[i]=='a')
        cnta++;
    }
    if(cnta==0||cnta==s.size())
    printf("No\n");
    else
    printf("Yes\n");
    return 0;
}