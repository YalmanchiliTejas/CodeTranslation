#include<bits/stdc++.h>
using namespace std;

int tb[60][30];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            tb[i][s[j]-'a']++;
        }
    }
    string ans="";
    for(int i=0;i<26;i++){
        int cnt=0;
        for(int j=0;j<N;j++){
            if(j==0)cnt=tb[j][i];
            else{
                if(tb[j][i]<cnt)cnt=tb[j][i];
            }
        }
        for(int j=0;j<cnt;j++){
            ans+=i+'a';
        }
    }
    cout<<ans<<endl;
    return 0;
}