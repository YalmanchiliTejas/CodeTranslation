#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;cin>>n;
        string s;cin>>s;
        int k;cin>>k;
        char d;
        for(int i=0;i<n;i++){
            if(i==k-1){
                d=s[i];
            }
        }
        for(int i=0;i<n;i++){
            if(d!=s[i]){
                s[i]='*';
            }
        }
        for(int i=0;i<n;i++)
        cout<<s[i];
        return 0;
}