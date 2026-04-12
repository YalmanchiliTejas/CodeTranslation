#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s[n];
    string ans="";
    vector<int> str(26,0);
    vector<int> str2(26,0);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<s[0].length();i++){
        str[s[0][i]-'a']++;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            str2[s[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            str[j]=min(str[j],str2[j]);
        }
        for(int j=0;j<26;j++){
            str2[j]=0;
        }
    }
    for(int i=0;i<26;i++){
        if(str[i]>0){
        for(int j=0;j<str[i];j++){
            ans+='a'+i;
        }
        }
    }
    cout << ans << endl;
}