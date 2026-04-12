#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c=s[k-1];
    char ans[n];
    for(int i=0;i<n;i++){
        if(c==s[i]){
            ans[i]=c;
        }
        else{
            ans[i]='*';
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
}