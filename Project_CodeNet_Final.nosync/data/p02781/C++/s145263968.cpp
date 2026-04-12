#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll com(ll N,ll R){
    if(R<0 || R>N) return 0;
    if(R==1) return N;
    else if(R==2) return N*(N-1)/2;
    else return N*(N-1)*(N-2)/6;
}

ll pow(ll N,ll k){
    ll res=1;
    rep(i,k) res*=N;
    return res; 
}

string S;
int N,K;

ll solve(int i,int k,int smaller){
    if(i==N){
        if(k==0) return 1;
        else return 0;
    }
    if(k==0) return 1;

    if(smaller) return com(N-i,k)*pow(9,k);
    else{
        if(S[i]=='0') return solve(i+1,k,false);
        else{
            ll zero=solve(i+1,k,true);
            ll aida=solve(i+1,k-1,true)*(S[i]-'1');
            ll icchi=solve(i+1,k-1,false);
            return zero+aida+icchi;
        }
    }
}

int main(){
    cin>>S>>K;
    N=S.size();
    cout<<solve(0,K,false)<<endl;
}