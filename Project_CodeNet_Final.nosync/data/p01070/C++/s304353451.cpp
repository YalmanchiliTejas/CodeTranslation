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
namespace SA{
    const int MAX=1000000;
    int N,K;
    int tmp[MAX+1],rank[MAX+1];
    bool compare_sa(int i,int j){
        if(rank[i]!=rank[j])return rank[i]<rank[j];
        else{
            int ri=(i+K<=N)?rank[i+K]:-1;
            int rj=(j+K<=N)?rank[j+K]:-1;
            return ri<rj;
        }
    }

    vector<int> construct_sa(string S){
        N=S.size();
        vector<int>sa(N+1);
        for(int i=0;i<=N;i++)sa[i]=i;
        for(int i=0;i<=N;i++){
            rank[i]=i==N?-1:S[i];
        }

        for(K=1;K<=N;K*=2){
            sort(sa.begin(),sa.end(),compare_sa);
            tmp[sa[0]]=0;
            for(int i=1;i<=N;i++){
                tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
            }
            for(int i=0;i<=N;i++)rank[i]=tmp[i];
        }
        return sa;
    }

    pint contain(string &S,vector<int>&sa,string &T){
        int a=0,b=S.size();
        while(b-a>1){
            int c=(a+b)/2;
            if(S.compare(sa[c],T.size(),T)<0)a=c;
            else b=c;
        }
        if(S.compare(sa[b],T.size(),T)!=0)return pint(-1,-1);
        pint ret(b,-1);
        a=b;b=S.size()+1;
        while(b-a>1){
            int c=(a+b)/2;
            if(S.compare(sa[c],T.size(),T)==0)a=c;
            else b=c;
        }
        ret.se=b;
        return ret;
    }
    vector<int> construct_lcp(string &S,vector<int>&sa){
        vector<int>lcp;
        N=S.size();
        for(int i=0;i<=N;i++)rank[sa[i]]=i;

        int h=0;
        lcp[0]=0;
        for(int i=0;i<N;i++){
            int j=sa[rank[i]-1];

            if(h>0)h--;
            for(;j+h<N&&i+h<N;h++){
                if(S[j+h]!=S[i+h])break;
            }
            lcp[rank[i]-1]=h;
        }
        return lcp;
    }
}

struct segtree{
    static const int SEG=1<<17;
    vector<vint>dat;
    void init(vint v){
        dat.resize(SEG*2);
        rep(i,v.size()){
            dat[i+SEG-1].pb(v[i]);
        }
        for(int i=SEG-2;i>=0;i--){
            dat[i].resize(dat[i*2+1].size()+dat[i*2+2].size());
            merge(dat[i*2+1].begin(),dat[i*2+1].end(),dat[i*2+2].begin(),dat[i*2+2].end(),dat[i].begin());
        }
    }
    int get(int a,int b,int x,int y,int k=0,int l=0,int r=SEG){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return lower_bound(all(dat[k]),y)-lower_bound(all(dat[k]),x);
        return get(a,b,x,y,k*2+1,l,(l+r)/2)+get(a,b,x,y,k*2+2,(l+r)/2,r);
    }
};

string S;
int Q;
segtree seg;
signed main(){
    cin>>S>>Q;
    vint sa=SA::construct_sa(S);
    vint rank(sa.size());
    rep(i,sa.size())rank[sa[i]]=i;
    seg.init(rank);
    while(Q--){
        int l,r;
        string M;
        cin>>l>>r>>M;
        r++;
        pint p=SA::contain(S,sa,M);
        if(p.fi==-1||r-l<M.size())printf("0\n");
        else{
            r-=M.size()-1;
            printf("%lld\n",seg.get(l,r,p.fi,p.se));
        }
    }
    return 0;
}