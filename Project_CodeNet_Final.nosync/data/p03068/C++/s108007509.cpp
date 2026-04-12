#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n; cin>>n;
    string s;
    cin>>s;
    int k; cin>>k;
    char x=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=x) cout<<'*';
        else cout<<s[i];
    }
}