#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define Int long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 

Int N,M,K;
Int X,Y,Z,D;

Int B,C;

const long MOD=(long)(1e9+7);
const int MAXN=500005;


vector<Int> adj[MAXN];
vector<Int> degree;
bool VIS[MAXN];     

Int mul(Int x,Int y){
    return ((x%MOD)*(y%MOD))%MOD;
}


long long ModExpo(long long x,unsigned long long y,long long M){
    Int ans=1;
    ans=(long long)ans;
    
    while(y>0){
        if(y&1) ans=((ans%M)*(x%M))%M;
        y>>=1LL;
        x=((x%M)*(x%M))%M;
    }
    return ans%M;
}

long long ModInv(long long n){
    return ModExpo(n,MOD-2,MOD);
}

int main()
{
       cin>>N;
       vector<Int> A(N);
       for(auto &x:A) cin>>x;
       
       Int sum=0;
       
       for(int i=0;i<N;++i) sum=(sum%MOD + A[i]%MOD)%MOD;
       sum=mul(sum,sum);
       Int removeSum=0;
       for(int i=0;i<N;++i) removeSum=(removeSum%MOD+mul(A[i],A[i]))%MOD;
       
       
       sum=(sum-removeSum+MOD)%MOD;
     
       
       Int ans=(sum*ModInv(2LL))%MOD;
       cout<<ans<<"\n";
}