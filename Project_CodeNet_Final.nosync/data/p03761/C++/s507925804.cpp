#include <iostream>
#include<string>
using namespace std;
int num[100][200];
void get_num( string s ,int i)
{
    for(int k=0;k<s.size();k++)
    {
        num[i][s[k]]++;
    }
    return ;
}
int main()
{
    int n; cin>>n; string s[200];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        get_num(s[i],i);
    }
    int ans[200]; for(int i=0;i<200;i++)ans[i]=1e9;
    for(int i=0;i<n;i++)
    {
        for(int k='a';k<='z';k++)
        {
            ans[k]=min(ans[k],num[i][k]);
        }
    }
    for(int i='a';i<='z';i++)
    {
        while(ans[i]--)cout<<char(i);
    }
}
