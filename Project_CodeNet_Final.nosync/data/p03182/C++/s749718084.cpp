#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int N=2e5+9,inf=1e18;
int n,m,sum,tr[4*N],lz[4*N];
vector <pair<int,int> > ev[N];
void shift(int id){
    tr[2*id]+=lz[id],lz[2*id]+=lz[id];
    tr[2*id+1]+=lz[id],lz[2*id+1]+=lz[id];
    lz[id]=0;
}
void upt(int x,int y,int d,int id=1,int l=0,int r=n){
    if(x>r or l>y)return;
    if(l>=x and r<=y){
        tr[id]+=d,lz[id]+=d;
        return;
    }
    int mid=(l+r)/2;
    shift(id);
    upt(x,y,d,2*id,l,mid);
    upt(x,y,d,2*id+1,mid+1,r);
    tr[id]=max(tr[2*id],tr[2*id+1]);
}
int ask(int x,int y,int id=1,int l=0,int r=n){
    if(x>r or l>y)return -inf;
    if(l>=x and r<=y)return tr[id];
    int mid=(l+r)/2;
    shift(id);
    return max(ask(x,y,2*id,l,mid),ask(x,y,2*id+1,mid+1,r));
}
int32_t main(){
    if(fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin),
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l,r,x;
        cin >> l >> r >> x;
        ev[r].push_back({l,x});
        sum+=x;
    }
    upt(0,n,sum);
    for(int i=1;i<=n;i++){
        upt(i,i,ask(0,i-1)-sum);
        for(auto j:ev[i])
            upt(0,j.f-1,-j.s);
    }
    cout << tr[1] << endl;
}
