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

const int SEG=1<<17;
int cnt[SEG*2];
bool put[SEG*2];
int dat[SEG*2];

inline void push(int k){
    if(!put[k])return;
    dat[k]=cnt[k];
    if(k<SEG-1){
        put[k*2+1]=put[k*2+2]=1;
    }
    put[k]=0;
}

void update(int a,int b,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        put[k]=1;
        push(k);
        return;
    }
    update(a,b,k*2+1,l,(l+r)/2);
    update(a,b,k*2+2,(l+r)/2,r);
    dat[k]=dat[k*2+1]+dat[k*2+2];
}

void pushAll(int k){
    if(k)pushAll((k-1)/2);
    push(k);
    if(k<SEG-1){
        push(k*2+1);
        push(k*2+2);
    }
}

void addLine(int k){
    int kk=k+SEG-1;
    pushAll(kk);
    cnt[kk]++;
    while(kk){
        kk=(kk-1)/2;
        cnt[kk]++;
    }
}

void remLine(int k){
    int kk=k+SEG-1;
    pushAll(kk);
    cnt[kk]--;
    dat[kk]=0;
    while(kk){
        kk=(kk-1)/2;
        cnt[kk]--;
        dat[kk]=dat[kk*2+1]+dat[kk*2+2];
    }
}

void toZero(int k){
    int kk=k+SEG-1;
    pushAll(kk);
    dat[kk]=0;
    while(kk){
        kk=(kk-1)/2;
        dat[kk]=dat[kk*2+1]+dat[kk*2+2];
    }
}

int aggregate(int a,int b,int k=0,int l=0,int r=SEG){
    push(k);
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return dat[k];
    return aggregate(a,b,k*2+1,l,(l+r)/2)+aggregate(a,b,k*2+2,(l+r)/2,r);
}

struct UF{
    vint par,cnt;
    void init(int n){
        par.resize(n);cnt.resize(n);
        rep(i,n){
            par[i]=i;
            cnt[i]=0;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        cnt[x]+=cnt[y];
        par[y]=x;
    }
};

int W,H,N;

vint xs;
set<tuple<int,int,int>>abn;
set<int>ls;
UF uf;
int tail;

set<tuple<int,int,int>>::iterator obtain(int l,int r){
    if(r==-1){
        auto it=abn.lower_bound(make_tuple(l,-1,-1));
        if(it==abn.end()||get<0>(*it)!=l)return abn.end();
        return it;
    }
    else{
        auto it=abn.lower_bound(make_tuple(r,-1,-1));
        if(it==abn.begin())return abn.end();
        it--;
        if(get<1>(*it)!=r)return abn.end();
        return it;
    }
}

void query1(int x){
    x=lower_bound(all(xs),x)-xs.begin();
    auto it=ls.lower_bound(x);
    int r=*it;
    it--;
    int l=*it;
    auto it2=obtain(l,-1);
    if(it2!=abn.end()){
        int id;
        tie(l,r,id)=*it2;
        abn.erase(it2);
        abn.insert(make_tuple(l,x,id));
        abn.insert(make_tuple(x,r,id));
        uf.cnt[uf.find(id)]++;
    }
    else{
        toZero(l);
        abn.insert(make_tuple(l,x,tail));
        abn.insert(make_tuple(x,r,tail));
        uf.cnt[tail]=2;
        tail++;
    }
    ls.insert(x);
    addLine(x);
}

void query2(int x){
    x=lower_bound(all(xs),x)-xs.begin();
    auto it=obtain(-1,x);
    auto it2=obtain(x,-1);

    auto itit=ls.lower_bound(x);
    itit++;int r=*itit;itit--;itit--;int l=*itit;

    if(it!=abn.end()){
        if(it2!=abn.end()){
            int id=get<2>(*it),id2=get<2>(*it2);
            uf.unite(id,id2);uf.cnt[uf.find(id)]--;
            abn.erase(it);it2=obtain(x,-1);abn.erase(it2);
            abn.insert(make_tuple(l,r,id));
        }
        else{
            int id=get<2>(*it);
            abn.erase(it);abn.insert(make_tuple(l,r,id));
        }
    }
    else{
        if(it2!=abn.end()){
            int id=get<2>(*it2);
            toZero(l);
            abn.erase(it2);abn.insert(make_tuple(l,r,id));
        }
        else{

        }
    }
    ls.erase(x);remLine(x);
}

int query3(int x,int xx){
    //cout<<x<<" "<<xx<<"------------"<<endl;
    //each(it,abn)cout<<get<0>(*it)<<" "<<get<1>(*it)<<" "<<get<2>(*it)<<endl;

    x=lower_bound(all(xs),x)-xs.begin();
    xx=upper_bound(all(xs),xx)-xs.begin()-1;
    auto itit=ls.lower_bound(x);
    if(itit==ls.end())return 0;
    x=*itit;
    itit=ls.upper_bound(xx);
    if(itit==ls.begin())return 0;
    itit--;
    xx=*itit;
    if(x>=xx)return 0;

    int ret=aggregate(x,xx);

    while(true){
        auto it=abn.lower_bound(make_tuple(x,-1,-1));
        if(it==abn.end()||get<0>(*it)>=xx)break;
        int id=get<2>(*it);
        if(--uf.cnt[uf.find(id)]==0)ret++;
        abn.erase(it);
    }
    update(x,xx);
    return ret;
}


signed main(){
    scanf("%lld%lld%lld",&W,&H,&N);

    xs.pb(0);xs.pb(W);
    vector<tuple<int,int,int>>evs;
    evs.pb(make_tuple(0*3+1,0,W));
    evs.pb(make_tuple(H*3+1,0,W));

    rep(i,N){
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a==c){
            evs.pb(make_tuple(b*3,a,114514));
            evs.pb(make_tuple(d*3+2,a,1919810));
            xs.pb(a);
        }
        else{
            evs.pb(make_tuple(b*3+1,a,c));
        }
    }

    sort(all(xs));xs.erase(unique(all(xs)),xs.end());
    sort(all(evs));

    addLine(0);

    ls.insert(0);ls.insert(xs.size()-1);
    uf.init(N*3);

    int ans=0;
    bool flag=false;
    for(auto &latte:evs){
        int y,x,xx;
        tie(y,x,xx)=latte;

        if(y!=0&&!flag){
            flag=true;
            abn.clear();
        }

        if(xx==114514)query1(x);
        else if(xx==1919810)query2(x);
        else{
            ans+=query3(x,xx);
            //cout<<ans<<endl;
        }
    }

    printf("%lld\n",ans);
    return 0;
}