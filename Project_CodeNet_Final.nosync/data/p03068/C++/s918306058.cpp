#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1])s[i]='*';
    }
    cout<<s<<endl;
}
