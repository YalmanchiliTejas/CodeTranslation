#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
//const int MOD=998244353;

const double PI=3.14159265359;

vector<long long> len(51), pct(51);

long long getAns(int i, long long x){
    if(!i || !x) return x;
    
    if(x<=len[i-1]+1) return getAns(i-1,x-1);
    
    if(x==len[i-1]+2) return 1+pct[i-1];
    
    if(x==len[i]) return pct[i];
    
    return 1+pct[i-1]+ getAns(i-1,x-2-len[i-1]);
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long x;
    cin>>n>>x;
    
    
    
    len[0]=1;
    pct[0]=1;
    for(int i=1; i<=50; i++){
        len[i]=3+2*len[i-1];
        pct[i]=1+2*pct[i-1];
        
    }
    
    cout<<getAns(n,x);
    
    return 0;
}