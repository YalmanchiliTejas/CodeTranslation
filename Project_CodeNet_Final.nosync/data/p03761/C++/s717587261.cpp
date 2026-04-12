#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>

#include<string>
using namespace std;
char q[666][300];
string ans;
string s[666];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++){
            q[i][(int)s[i][j]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        int num=2e9;
        for(int j=0;j<n;j++){
            if(num>q[j][i]){
                num=q[j][i];
            }
        }
        for(int j=0;j<num;j++){
            ans+=(char)('a'+i);
        }
    }
    cout<<ans<<endl;
    return 0;
}