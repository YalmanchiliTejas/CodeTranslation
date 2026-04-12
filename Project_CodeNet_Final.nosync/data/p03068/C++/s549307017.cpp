#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int n;
    string s;
    int k;
    cin>>n>>s>>k;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k-1]){
            cout<<'*';
        }else{
            cout<<s[i];
        }
    }
    cout<<endl;
    
}
