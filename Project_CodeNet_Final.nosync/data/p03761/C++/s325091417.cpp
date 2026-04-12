#include <bits/stdc++.h>
using namespace std;
int n;
int a[50][26];
string ans="";
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<s.size();j++){
            a[i][s.at(j)-'a']++;
        }
    }
    for(int j=0;j<26;j++){
        int M=100;
        for(int i=0;i<n;i++){
            M=min(M,a[i][j]);
        }
        string s(M,'a'+j);
        ans+=s;
    }
    cout<<ans<<endl;
}