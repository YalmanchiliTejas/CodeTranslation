#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,i;
    string s;
    cin>>n>>s>>m;
    for(i=0;i<n;i++){
        if(s[i]==s[m-1])
            cout<<s[i];
        else cout<<"*";
    }
    cout<<endl;
}



