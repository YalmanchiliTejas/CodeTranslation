#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[26],b[26];
    string s;
    cin>>s;
    for(int i=0;i<26;i++) a[i]=0;
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    for(int i=1;i<n;i++){
        string t;
        cin>>t;
        for(int l=0;l<26;l++) b[l]=0;
        for(int j=0;j<t.size();j++){
            b[t[j]-'a']++;
        }
        for(int k=0;k<26;k++){
            a[k]=min(a[k],b[k]);
        }
        
    }
    bool flg=true;
    for(int i=0;i<26;i++){
        while(a[i]>0){
            cout<<char(97+i);
            flg=false;
            a[i]--;
        }
    }
    if(flg) cout<<endl;
}