#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
int L[55];
int P[55];
int calc(int n,int x){
    if(x<=0)return 0;
    if(n==0)return 1;
 
    int res=0;
    if(L[n-1]+1<=x)res+=P[n-1];
    else res+=calc(n-1,x-1);
 
    if(1+L[n-1]+1<=x)res++;
    if(1+L[n-1]+1+L[n-1]<=x)res+=P[n-1];
    else res+=calc(n-1,x-1-L[n-1]-1);
    return res;
}
 
signed main(){
    L[0]=1;
    P[0]=1;
    for(int i=1;i<55;i++){
        L[i]=L[i-1]*2+3;
        P[i]=P[i-1]*2+1;
    }
    int N,X;cin>>N>>X;
    cout<<calc(N,X)<<endl;
    return 0;
}