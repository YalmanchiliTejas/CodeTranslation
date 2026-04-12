#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
int latte[2222][2222];

int malta[2222][2222];

int N,A,B,C,D;

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

signed main(){
    for(int i=0;i<2222;i++){
        latte[i][0]=latte[i][i]=1;
        for(int j=1;j<i;j++)latte[i][j]=(latte[i-1][j-1]+latte[i-1][j])%mod;
    }

    cin>>N>>A>>B>>C>>D;
    for(int i=1;i<=N;i++){
        malta[i][0]=1;
        for(int j=1;i*j<=N;j++){
            malta[i][j]=malta[i][j-1]*latte[i*j-1][i-1]%mod;
        }
    }

    vint pre(1111);
    pre[0]=1;
    for(int i=A;i<=B;i++){
        vint nex(1111);
        for(int j=0;j<=N;j++)nex[j]=pre[j];
        for(int j=0;j<=N;j++){
            for(int k=C;k<=D&&j+k*i<=N;k++){
                add(nex[j+k*i],pre[j]*latte[N-j][k*i]%mod*malta[i][k]%mod);
            }
        }
        pre=nex;
    }
    cout<<pre[N]<<endl;
    return 0;
}
