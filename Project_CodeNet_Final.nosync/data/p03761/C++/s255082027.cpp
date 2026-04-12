#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[50];
    int c[26];
    for(int i=0;i<26;i++)c[i]=50;
    int cnt[26];
    for(int i=0;i<26;i++)cnt[i]=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)cnt[(int)(s[i][j]-97)]++;
        for(int i=0;i<26;i++){
            c[i]=min(cnt[i],c[i]);
            cnt[i]=0;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<c[i];j++)cout<<(char)(i+97);
    }
    cout<<endl;
    return 0;
}