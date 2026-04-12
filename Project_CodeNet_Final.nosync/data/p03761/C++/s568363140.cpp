#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    string s[n];
    int nnn[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        nnn[i]=s[i].size();
        sort(s[i].begin(),s[i].end());
    }
    int c[n+1][26]={};
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<nnn[i];j++){
            x=s[i][j];
            char y='a';
            for(int k=0;k<26;k++){
                if(x==y){
                    c[i][k]++;
                }
                y++;
            }
            
        }
        for(int k=0;k<26;k++){
                c[0][k]=min(c[0][k],c[i][k]);
        }
    }
    string ans="";
    char z='a';
    for(int i=0;i<26;i++){
        for(int j=0;j<c[0][i];j++){
            ans=ans+z;
            
        }
        z++;
        //cout<<c[0][i];
    }
    cout<<ans<<endl;



}