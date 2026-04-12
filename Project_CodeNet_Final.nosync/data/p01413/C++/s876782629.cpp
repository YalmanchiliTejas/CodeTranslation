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

int N,M,W,T;
int w[10],v[10];
int X[10],Y[10];
vector<int>lis[10],cost[10];

int tabled[1<<7],tablev[1<<7];

int F[10010];

void pre_calc(int b){
    memset(F,0,sizeof(F));
    rep(i,N){
        if(!(b>>i&1))continue;
        rep(j,W){
            rep(k,lis[i].size()){
                int vv=v[lis[i][k]]-cost[i][k];
                int ww=w[lis[i][k]];
                if(j+ww<=W)chmax(F[j+ww],F[j]+vv);
            }
        }
    }

    vector<int>p;
    rep(i,N)if(b>>i&1)p.pb(i);

    int min_dist=1001001001;
    do{
        int dist=0;
        rep(i,p.size()-1){
            dist+=abs(X[p[i+1]]-X[p[i]])+abs(Y[p[i+1]]-Y[p[i]]);
        }
        dist+=abs(X[p[0]])+abs(Y[p[0]]);
        dist+=abs(X[p[p.size()-1]])+abs(Y[p[p.size()-1]]);
        chmin(min_dist,dist);
    }while(next_permutation(all(p)));

    tabled[b]=min_dist;
    tablev[b]=F[W];
}

signed main(){
    cin>>N>>M>>W>>T;
    vector<string>hoge(M);
    rep(i,M){
        cin>>hoge[i]>>w[i]>>v[i];
    }
    rep(i,N){
        int l;
        cin>>l>>X[i]>>Y[i];
        lis[i].resize(l);cost[i].resize(l);
        rep(j,l){
            string s;
            cin>>s>>cost[i][j];
            lis[i][j]=find(all(hoge),s)-hoge.begin();
        }
    }

    reps(i,1,1<<N)pre_calc(i);

    memset(F,0,sizeof(F));
    rep(i,1<<N){
        for(int j=0;j<=T;j++){
            if(j+tabled[i]<=T){
                chmax(F[j+tabled[i]],F[j]+tablev[i]);
            }
        }
    }

    cout<<F[T]<<endl;
    return 0;
}