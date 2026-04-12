#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(30));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(char c : s) v[i][c-'a']++;
    }
    string ans="";
    for(char c='a';c<='z';c++){
        int r=1e9;
        for(int i=0;i<n;i++){
            r=min(r,v[i][c-'a']);
        }
        for(int i=0;i<r;i++) ans+=c;
    }
    cout<<ans<<endl;
}