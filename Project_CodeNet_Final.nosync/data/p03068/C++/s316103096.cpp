#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main(){
    cin>>n>>s>>k;
    char z = s[k-1];
    for(int i=0;i<n;i++){
        if(s[i] == z) continue;
        s[i] = '*';
    }
    cout<<s<<endl;
}   