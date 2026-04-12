// 怪文書 / Dubious Document
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[26][50];
string s;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[s[j]-'a'][i]++;
        }
    }
    for(int i=0;i<26;i++){
        sort(a[i],a[i]+n);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<a[i][0];j++){
            cout<<char(i+'a');
        }
    }
}