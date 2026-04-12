#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdio>

#include<string>
#include<vector>
using namespace std;
int n;
vector <int> cnt(26,1e9);
string ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector <int> v(26);
        for(int j=0;j<s.size();j++){
            v[(int)s[j]-'a']++;
        }
        for(int i=0;i<26;i++){
            cnt[i]=min(cnt[i],v[i]);
        }
    }
    for(int i=0;i<26;i++){
        cout<<string(cnt[i],i+'a');
    }
    puts("");
    return 0;
}