#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int a[n][26]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            a[i][v[i][j]-'a']++;
        }
    }
    //debug- correct until here
    /*for(int i=0;i<n;i++){
        for(int j=0;j<26;j++)cout<<a[i][j];
        cout<<endl;
    }*/
    vector<int>ans;
    int mn=12345;
    int temp=0;
    for(int i=0;i<26;i++){
        mn=12345;
        for(int j=0;j<n;j++){
            if(a[j][i]<mn)mn=a[j][i];
        }
        ans.push_back(mn);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++)cout<<char(i+97);
    }
	return 0;
}