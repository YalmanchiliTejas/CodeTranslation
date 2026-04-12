#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long



vector<vector<ll> >intervals;
vector<ll>dp;
vector<ll>st;
vector<ll>lazy;
vector<vector<ll> >endings;
void buildst(ll node,ll strt,ll ed){

    if(strt==ed){
        st[node] = dp[strt];
        return;
    }
    ll mid = strt+(ed-strt)/2;
    buildst(2*node,strt,mid);
    buildst(2*node+1,mid+1,ed);
    st[node] = max(st[2*node],st[2*node+1]);
    return;
}

void updaterangest(ll node,ll strt,ll ed,ll l,ll r,ll val){

        if(lazy[node]!=0){
            st[node] += lazy[node];

            if(strt != ed){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] =0;
        }

        if(r<strt || l>ed){
            return;
        }
        if(l<=strt && r>=ed){
            st[node] += val;
            if(strt !=ed){
                lazy[node*2] += val;
                lazy[node*2 +1] += val;
            }else{
                dp[strt] += val;
            }
            return;
        }
        ll mid = strt+(ed-strt)/2;
        updaterangest(2*node,strt,mid,l,r,val);
        updaterangest(2*node+1,mid+1,ed,l,r,val);
        st[node] = max(st[2*node],st[2*node+1]);
}

ll queryrangest(ll node,ll strt,ll ed,ll l,ll r){

        if(r<strt || l>ed){
            return -1;
        }
        if(lazy[node]!=0){
            st[node] += (ed-strt+1)*lazy[node];

            if(strt != ed){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] =0;
        }
        if(strt>=l && r>=ed){
            return st[node];
        }
        ll mid = strt+(ed-strt)/2;
        ll a = queryrangest(node*2,strt,mid,l,r);
        ll b = queryrangest(node*2+1,mid+1,ed,l,r);
        return max(a,b);
}


void solve(){
  ll n,m;cin>>n>>m;
  dp.resize(n);
  endings.resize(n);
  st.resize(4*n+1);
  lazy.resize(4*n+1);
  buildst(1,0,n-1);
  intervals.resize(m,vector<ll>(3));
  for(ll i=0;i<m;i++){
    cin>>intervals[i][0]>>intervals[i][1]>>intervals[i][2];
    intervals[i][0]--;
    intervals[i][1]--;
    endings[intervals[i][1]].push_back(i);
  }
  for(ll i=0;i<endings[0].size();i++){
        ll idx = endings[0][i];
    updaterangest(1,0,n-1,intervals[idx][0],intervals[idx][1],intervals[idx][2]);
  }



  for(ll i=1;i<n;i++){

        ll prevmx = max(0LL,queryrangest(1,0,n-1,0,i-1));
        updaterangest(1,0,n-1,i,i,prevmx);
        for(ll j=0;j<endings[i].size();j++){
            ll idx = endings[i][j];
            updaterangest(1,0,n-1,intervals[idx][0],intervals[idx][1],intervals[idx][2]);
        }

  }
  cout << max(0LL,queryrangest(1,0,n-1,0,n-1))<<"\n";
}

int main(){
//    cin.tie(0);
//    cout.tie(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);

    //cout.precision(10);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
