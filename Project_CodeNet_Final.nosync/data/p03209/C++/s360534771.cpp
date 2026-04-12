#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
int const N_MAX=50;
int N;
ll X;
vector<ll> f(N_MAX),p(N_MAX);

ll G(int n,ll x){
    if(x==0){
        return 0;
    }else if(n==0){
        return 1;
    }
    if(x>=f[n-1]+2) return 1+p[n-1]+G(n-1,x-(f[n-1]+2));
    return G(n-1,x-1);
}

int main(){
    cin >> N >> X;
    
    f[0]=1;
    p[0]=1;
    rep2(i,1,N){
        f[i]=2*f[i-1]+3;
        p[i]=2*p[i-1]+1;
    }

    cout << G(N,X) << endl;
    

}