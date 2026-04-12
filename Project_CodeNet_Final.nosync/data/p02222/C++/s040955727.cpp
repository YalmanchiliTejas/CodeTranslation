#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
//#define endl "/n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

vector<ll> v[100001];

struct Node{
    ll dep;
    ll par;
    ll chidep;
    vector<ll> chi;
    ll maxi[3];
};

Node node[100001];
void parset(ll i){
    ll chidep=-1;
    rep(j,0,v[i].size()-1){
        if(node[v[i][j]].par==-1){
            node[v[i][j]].par=i;
            node[i].chi.pb(v[i][j]);
            node[v[i][j]].dep=node[i].dep+1;
            parset(v[i][j]);
            chidep=max(chidep,node[v[i][j]].chidep+1);
        }
    }
    if(chidep==-1){
        node[i].chidep=0;
    }else{
        node[i].chidep=chidep;
    }
}
priority_queue<ll> q;
void hoge(ll i){
    while(q.size()>0)q.pop();
    if(i==1){
        rep(j,0,node[1].chi.size()-1){
            q.push(node[node[1].chi[j]].chidep+1);
        }
        ll j=0;
        while(j<3 && q.size()>0){
            node[1].maxi[j]=q.top();q.pop();
            j++;
        }
        rep(j,0,node[1].chi.size()-1){
            hoge(node[1].chi[j]);
        }
        return ;
    }
    if(node[i].chi.size()>0){
        rep(j,0,node[i].chi.size()-1){
            q.push(node[node[i].chi[j]].chidep+1);
        }
    }
    bool used=true;
    if(node[i].par==1 && node[1].chi.size()==1){
        q.push(1);
    }else{
        rep(j,0,1){
            if(node[node[i].par].maxi[j]!=-1){
                if(node[node[i].par].maxi[j]!=node[i].chidep+1){
                    q.push(node[node[i].par].maxi[j]+1);
                    break;
                }else{
                    if(used){
                        used=false;
                        continue;
                    }else{
                        q.push(node[node[i].par].maxi[j]+1);
                        break;
                    }
                }
            }
        }
    }
    ll j=0;
    while(j<3 && q.size()>0){
        node[i].maxi[j]=q.top();q.pop();
        j++;
    }
    if(node[i].chi.size()>0){
        rep(j,0,node[i].chi.size()-1){
            hoge(node[i].chi[j]);
        }
    }
    return ;
    
}

int main(){
    ll n;cin>>n;
    ll a[n],b[n];
    if(n==1){
        cout<<1<<endl;
        return 0;
    }else if(n==2){
        rep(i,0,n-2){
            cin>>a[i]>>b[i];
            v[a[i]].pb(b[i]);
            v[b[i]].pb(a[i]);
        }
        cout<<11<<endl;
        return 0;
    }
    
    rep(i,0,n-2){
        cin>>a[i]>>b[i];
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    rep(i,1,n){
        node[i].par=-1;
        rep(j,0,2){
            node[i].maxi[j]=-1;
        }
    }
    node[1].par=0;
    node[1].dep=0;
    parset(1);
    
    hoge(1);
    ll ans=-1;
    ll comp;
    rep(i,1,n){
        if(node[i].maxi[2]==-1)continue;
        if(node[i].maxi[0]==node[i].maxi[1] && node[i].maxi[1]==node[i].maxi[2]){
            comp=node[i].maxi[0]+node[i].maxi[2]-1;
        }else{
            comp=node[i].maxi[0]+node[i].maxi[2];
        }
        ans=max(ans,comp);
    }
    rep(i,1,n){
        if(i>=3 && i<=ans){
            cout<<0;
        }else{
            cout<<1;
        }
    }
    cout<<endl;
    
    return 0;
}
