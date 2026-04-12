#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<60;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll popcount(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    int d[a][b];
    rep(i,0,a)rep(j,0,b)cin>>d[i][j];
    rep(i,0,a){
        rep(j,0,b-1){
            if(d[i][j+1]<d[i][j]){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    rep(i,0,b){
        rep(j,0,a-1){
            if(d[j+1][i]<d[j][i]){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    rep(i,0,a){
        rep(j,0,b-2){
            int sa1=d[i][j+1]-d[i][j],sa2=d[i][j+2]-d[i][j+1];
            if(sa1<sa2||sa1<0||sa2<0){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    rep(i,0,b){
        rep(j,0,a-2){
            int sa1=d[j+1][i]-d[j][i],sa2=d[j+2][i]-d[j+1][i];
            if(sa1<sa2||sa1<0||sa2<0){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    vector<pii> v[301];
    int now=201;
    int m=199;
    rep(i,0,a){
        rep(j,0,b){
            int dx=0,dy=0;
            vector<pipi> w;
            rep(k,0,100){
                rep(l,0,100){
                    int rrr=0;
                    rep(ii,0,a){
                        rep(jj,0,b){
                            int sa=k*(ii-i)+l*(jj-j);
                            //if(i==1&&j==3&&k==3&&l==1)cout<<ii<<" "<<jj<<endl;
                            if(d[i][j]+sa<d[ii][jj]){
                                rrr=1;
                                break;
                            }
                        }
                        if(rrr)break;
                    }
                    if(rrr==0){
                        w.push_back({(i+1)*k+(j+1)*l,{k,l}});
                    }
                }
            }
            sort(w.begin(),w.end());
            if(w.size()==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
            //cout<<i<<" "<<j<<endl;
            dx=w[0].second.first;
            dy=w[0].second.second;
            //cout<<dx<<" "<<dy<<endl;
            int ama=d[i][j]-dx*(i+1)-dy*(j+1);
            if(ama<0){
                cout<<"Impossible"<<endl;
                return 0;
            }
            v[dx+1].push_back({now,0});
            v[now].push_back({200-dy,ama});
            now++;
            m+=2;
        }
    }
    cout<<"Possible"<<endl;
    cout<<300<<" "<<m<<endl;
    rep(i,1,100){
        cout<<i<<" "<<i+1<<" "<<'X'<<endl;
    }
    cout<<100<<" "<<101<<" "<<0<<endl;
    rep(i,101,200)cout<<i<<" "<<i+1<<" "<<'Y'<<endl;
    rep(i,1,301){
        rep(j,0,v[i].size())cout<<i<<" "<<v[i][j].first<<" "<<v[i][j].second<<endl;
    }
    cout<<1<<" "<<200<<endl;
}






