#include<bits/stdc++.h>
using namespace std;
struct node
{
    string s;
}a[55];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].s;
    for(char ch='a';ch<='z';ch++)
    {
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int k=0;
            for(int j=0;j<a[i].s.size();j++)
                if(a[i].s[j]==ch) k++;
            ans=min(ans,k);
        }
        for(int j=0;j<ans;j++)
            printf("%c",ch);
    }
    printf("\n");
}
