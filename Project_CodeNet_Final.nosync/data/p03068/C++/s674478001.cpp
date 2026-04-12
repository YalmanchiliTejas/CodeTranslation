#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string s; cin>>n>>s>>k;
    char left = s[k-1];
    for(int i=0; i<n; i++) {
        s[i]=(s[i]!=left?'*':left);
    }
    cout << s << endl;
}