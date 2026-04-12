#include<bits/stdc++.h>
using namespace std;
int cnt[26][50];
string s[50];
int main()
{
    int n;
    cin>>n;
    string ans="";
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)
            cnt[s[i][j]-'a'][i]++;
    }
    for(int i=0;i<26;i++)
    {
        sort(cnt[i],cnt[i]+n);
        ans.append(cnt[i][0], 'a'+i);
    }
    cout<<ans<<endl;
    return 0;
}
