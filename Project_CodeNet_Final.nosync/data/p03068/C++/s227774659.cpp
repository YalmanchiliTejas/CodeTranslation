#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k,i;
    cin>>n;
    string str;
    cin>>str;
    cin>>k;
    char s=str[k-1];
    for(i=0;i<str.length();i++){
        if(str[i]==s)
            cout<<str[i];
        else
            cout<<"*";
    }
    cout<<endl;
    return 0;
}
