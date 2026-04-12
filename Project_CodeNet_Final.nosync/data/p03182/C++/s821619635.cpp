#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 200*1000+10;
const LL INF = (LL)1000*1000*1000*1000*1000*1000;
int n,m,R,log2n;
vector<pi>events[MAXN];
LL q[MAXN];
LL totals;
LL res=0;

struct Node {
    LL f,g;
};

Node T[(1<<20)];

void propagate(int x) {
    T[2*x].g+=T[x].g;
    T[2*x+1].g+=T[x].g;
    T[x].g=0;
}

void updateTf(int a) {
    while(a>1) {
        a/=2;
        T[a].f = min(T[2*a].f+T[2*a].g,T[2*a+1].f+T[2*a+1].g);
    }
}

void update(int a,int b, LL c) {
    a+=R; b+=R;
    for(int i=log2n; i>0;i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    int pa=a,pb=b;
    T[a].g+=c;
    if(a!=b) T[b].g+=c;
    while(a/2!=b/2) {
        if(a%2==0) T[a+1].g+=c;
        if(b%2==1) T[b-1].g+=c;
        a/=2;
        b/=2;
    }
    updateTf(pa); updateTf(pb);
}

LL query(int a,int b) {
    a+=R; b+=R;
    for(int i=log2n; i>0;i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    updateTf(a); updateTf(b);
    LL w = min(T[a].f+T[a].g,T[b].f+T[b].g);
    while(a/2!=b/2) {
        if(a%2==0) w=min(w,T[a+1].f+T[a+1].g);
        if(b%2==1) w=min(w,T[b-1].f+T[b-1].g);
        a/=2;
        b/=2;
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m;i++) {
        int l,r,c;
        cin>>l>>r>>c;
        events[r].emplace_back(l,c);
        q[l]+=c;
    }
    int pom=1;
    while(pom<=n) {
        log2n++;
        pom*=2;
    }
    R = pom;
    for(int i=1; i<=n;i++) {
        for(auto p:events[i-1]) {
            update(0,p.ST-1,p.ND);
        }
        totals+=q[i];
        LL tmp = query(0,i-1);
        //cout<<totals<<" "<<tmp<<"\n";
        res=max(res,totals-tmp);
        update(i,i,tmp);
    }
    cout<<res;
}
