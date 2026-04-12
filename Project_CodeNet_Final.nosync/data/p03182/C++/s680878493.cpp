#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
struct t{
    int l,r,val;
} v[mxN];
struct EV{
    int type,x,id;
    bool operator<(const EV &o) const{
        return x<o.x;
    }
};
vector<EV>ev;
int n,m,dp[mxN];
int seg[4*mxN],lazy[4*mxN];
void down(int i,int j,int no){
    if(!lazy[no])return;
    seg[no]+=lazy[no];
    if(i!=j){
        lazy[2*no]+=lazy[no];
        lazy[2*no+1]+=lazy[no];
    }
    lazy[no]=0;
}
int query(int A,int B,int i=0,int j=n,int no=1){
    if(j<A || i>B||i>j)return -1e18;
    down(i,j,no);
    if(A<=i && j<=B)return seg[no];
    int m=(i+j)/2;
    return max(query(A,B,i,m,2*no),query(A,B,m+1,j,2*no+1));
}
void upd(int k,int A,int B,int i=0,int j=n,int no=1){
    //cout<<k<<" "<<A<<" "<<B<<" "<<i<<" "<<j<<" "<<no<<"\n";
    down(i,j,no);
    if(j<A || i>B || i>j)return;    
    if(A<=i && j<=B){
        seg[no]+=k;
        if(i!=j){
            lazy[2*no]+=k;
            lazy[2*no+1]+=k;
        }
        return;
    }
    int m=(i+j)/2;
    upd(k,A,B,i,m,2*no);
    upd(k,A,B,m+1,j,2*no+1);
    seg[no]=max(seg[2*no],seg[2*no+1]);
}   

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>v[i].l>>v[i].r>>v[i].val;
        v[i].r++;
        ev.pb({0,v[i].l,i});
        ev.pb({1,v[i].r,i});
    }
    sort(ev.begin(),ev.end());
    int cur=0;
    for(int i=1;i<=n;i++){
        while(cur<2*m && ev[cur].x==i){
            if(ev[cur].type==0){
                upd(v[ev[cur].id].val,0,i-1);
            }
            else{
                upd(-v[ev[cur].id].val,0,v[ev[cur].id].l-1);
            }
            cur++;
        }
        //cout<<query(0,0)<<"\n";
        dp[i]=query(0,i-1);
        upd(dp[i],i,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans;
    
}