#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int s[50][26]={0};
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        for(int j=0;j<a.size();j++){
            s[i][a[j]-'a']++;
        }
    }
    string tmp="";
    for(int j=0;j<26;j++){
        int k=10000;
        for(int i=0;i<n;i++){
            k=min(k,s[i][j]);
        }
        for(int i=0;i<k;i++){
            tmp+='a'+j;
        }
    }
    cout<<tmp<<endl;
    return 0;
}
