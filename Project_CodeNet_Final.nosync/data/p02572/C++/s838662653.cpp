#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long p = 1e9+7;
    cin>>n;
    vector<int >nos(n+1,0),temp(n+1,0);
    for(int i=1;i<=n;i++){cin>>temp[i];nos[i]= (nos[i-1]+temp[i])%p;}
    int ans=0;
    for(int i=2;i<=n;i++){
        ans = (ans + ((long long)temp[i]*(long long)nos[i-1])%p)%p;
    }
    cout<<ans;
    
}