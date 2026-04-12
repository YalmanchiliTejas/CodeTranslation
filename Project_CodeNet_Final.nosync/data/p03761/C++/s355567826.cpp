#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
char s[55][55];
int num[26];
int tmp[26];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for (int i=0;i<26;i++)
    {
        num[i]=100;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<26;j++)
            tmp[j]=0;
        for (int j=0;s[i][j];j++)
        {
            tmp[s[i][j]-'a']++;
        }
        for (int j=0;j<26;j++)
            num[j]=min(num[j],tmp[j]);
    }
    for (int i=0;i<26;i++)
    {
        if (!num[i])
            continue;
        for (int j=0;j<num[i];j++)
        {
            cout<<(char)('a'+i);
        }
    }
    return 0;
}
