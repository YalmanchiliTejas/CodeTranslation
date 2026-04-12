#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int alpha[n][26];
    int l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++)alpha[i][j]=0;
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            alpha[i][s[j]-'a']++;
        }
    }
    string ans="";
    for(int j=0;j<26;j++){
        int m=50;
        for(int i=0;i<n;i++){
            m=min(m,alpha[i][j]);
        }
        for(int i=0;i<m;i++){
            ans+=('a'+j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
