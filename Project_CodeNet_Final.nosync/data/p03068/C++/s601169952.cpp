#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char s[200005];
    scanf("%s",s);
    int k;
    cin>>k;
    char c=s[k-1];
    for(int i=0;i<n;i++)
    {
        if(s[i]==c)
        cout<<c;
        else
        cout<<'*';
    }
    return 0;
}