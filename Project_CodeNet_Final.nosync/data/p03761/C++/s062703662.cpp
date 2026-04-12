#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>sv(n,vector<int>(26));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            sv[i][s[j]-'a']++;
        }
    }   
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<26;j++){
            sv[i+1][j]=min(sv[i][j],sv[i+1][j]);
        }
    }
    string s="";
    for(int j=0;j<26;j++){
        char tempchar=j+'a';
        for(int k=0;k<sv[n-1][j];k++){
            s+=tempchar;
        }        
    }
    cout<<s<<endl;
    return 0;
}
