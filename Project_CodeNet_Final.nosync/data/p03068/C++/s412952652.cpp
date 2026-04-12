#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;

    char check = s[k-1];

    for(int i=0;i<s.size();i++){
        if(s[i]!=check){
            s[i] = '*';
        }
    }
    cout<<s<<endl;
    return 0;
}