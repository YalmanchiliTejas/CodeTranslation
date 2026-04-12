#include<bits/stdc++.h>
using namespace std;

#define int long long
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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


struct segtree{
    static const int SEG=1<<19;
    vint ma,put;
    segtree():ma(SEG*2),put(SEG*2){}
    inline void push(int k){
        ma[k]+=put[k];
        if(k<SEG-1){
            put[k*2+1]+=put[k];
            put[k*2+2]+=put[k];
        }
        put[k]=0;
    }
    void add(int a,int b,int x=0,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]+=x;
            push(k);
            return;
        }
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        ma[k]=max(ma[k*2+1],ma[k*2+2]);
    }
    int get(int a,int b,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return LLONG_MIN;
        if(a<=l&&r<=b)return ma[k];
        return max(get(a,b,k*2+1,l,(l+r)/2),get(a,b,k*2+2,(l+r)/2,r));
    }
};

int N;
int A[555555];
segtree segA,segB;

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    rep(i,N/2){
        int d=A[i]-A[N-1-i];
        segA.add(i,i+1,d);
        segB.add(i,i+1,-d);
    }

    int Q;scanf("%lld",&Q);
    while(Q--){
        int l,r,x;
        scanf("%lld%lld%lld",&l,&r,&x);
        l--;
        if(l<=N/2-1&&N/2<r){
            int llen=N/2-l,rlen=r-N/2;
            if(llen<rlen){
                l=N/2+llen;
            }
            else if(llen>rlen){
                r=N/2-rlen;
            }
            else{
                l=r=0;
            }
        }
        if(N/2<=l){
            int ll=N-r;
            int rr=N-l;
            l=ll;r=rr;x*=-1;
        }
        segA.add(l,r,x);
        segB.add(l,r,-x);

        if(segA.get(0,N/2)==0&&segB.get(0,N/2)==0)puts("1");
        else puts("0");

        //rep(i,N/2)cout<<segA.get(i,i+1)<<" ";cout<<endl;
        //rep(i,N/2)cout<<segB.get(i,i+1)<<" ";cout<<endl;
    }
    return 0;
}