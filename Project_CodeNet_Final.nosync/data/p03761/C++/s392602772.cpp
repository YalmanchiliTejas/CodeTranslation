#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> flg;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        flg.push_back(vector<int>(26));
        for(int j=0;j<s[i].size();j++){
            flg[i][s[i][j]-'a']++;
        }
    }
    vector<int> res(26);
    for(int i=0;i<26;i++){
        int ans=1e9;
        for(int j=0;j<n;j++){
            ans=min(ans,flg[j][i]);
        }
        res[i]=ans;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<res[i];j++)printf("%c",'a'+i);
    }
    printf("\n");
    return 0;
}