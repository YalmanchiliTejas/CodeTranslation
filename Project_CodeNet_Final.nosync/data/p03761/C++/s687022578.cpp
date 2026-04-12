#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(26));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[i][s[j]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        int minv=20000;
        for(int j=0;j<n;j++){
            minv=min(minv,a[j][i]);
        }
        for(int j=0;j<minv;j++){
            cout<<char(i+'a');
        }
    }
    cout<<endl;
    return 0;
}