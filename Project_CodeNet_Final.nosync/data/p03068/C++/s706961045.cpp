#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n,k;
    string s;

    cin>>n>>s>>k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]) s[i]='*';
    }
    cout<<s<<endl;
}