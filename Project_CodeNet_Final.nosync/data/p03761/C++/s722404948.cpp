#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    int a[n][26]={};
    for(int i=0;i<n;i++){
        cin>>s;
        for(auto j:s){
            a[i][j-'a']++;
        }
    }

    int ans[26];
    for(int i=0;i<26;i++){
        ans[i]=1e5;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            ans[j]=min(ans[j],a[i][j]);
        }
    }
    bool ng=true;
    string res="";
    for(int i=0;i<26;i++){
        if(ans[i]!=0) ng=false;
        for(int j=0;j<ans[i];j++){
            res+=(char)(i+'a');
        }
    }

    if(ng){
        cout<<""<<endl;
        return 0;
    }

    cout<<res;

}