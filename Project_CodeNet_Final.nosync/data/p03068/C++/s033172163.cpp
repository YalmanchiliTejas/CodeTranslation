#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    string s;
    cin>>n>>s;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    cout<<s<<endl;
}
 