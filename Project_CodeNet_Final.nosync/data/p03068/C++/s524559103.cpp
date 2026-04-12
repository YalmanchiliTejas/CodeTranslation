#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    int n,k;
    cin>>n;
    cin>>s;
    cin>>k;
    char S = s[k-1];
    for(int i=0;i<s.size();i++) {
        if(s[i]==S) {
            cout<<s[i];
        }
        else {
            cout<<"*";
        }
    }
    cout<<endl;
    return 0;
}
