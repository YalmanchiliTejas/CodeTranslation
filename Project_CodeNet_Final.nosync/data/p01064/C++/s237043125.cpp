#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
int a,d;
int M;
int x[222222],y[222222],z[222222];
int K;

signed main(){
    cin>>N>>a>>d>>M;
    rep(i,M)cin>>x[i]>>y[i]>>z[i],y[i]--,z[i]--;
    cin>>K;K--;

    int k=K;
    for(int i=M-1;i>=0;i--){
        if(x[i]||k<y[i]||z[i]<k)continue;
        int tmp=k-y[i];
        k=z[i]-tmp;
    }

    int v=a+d*k;

    rep(i,M){
        if(k<y[i]||z[i]<k)continue;
        if(x[i]==0){
            int tmp=k-y[i];
            k=z[i]-tmp;
        }
        else if(x[i]==1){
            v++;
        }
        else{
            v/=2;
        }
    }
    cout<<v<<endl;
    return 0;
}