#include <bits/stdc++.h>
typedef long long ll;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt=0,ans=0,a[ohara],b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,k;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>n;
    rep(i,n)cin>>a[i];
    if(n<=10){
        vector<ll> p(n);
        rep(i,n)p[i]=i;
        do{
            ll data[20];
            rep(i,n){
                data[i]=a[p[i]];
            }
            rep(i,n-1){
                cnt+=abs(data[i]-data[i+1]);
            }
            ans=max(ans,cnt);
            cnt=0;
        }while(next_permutation(all(p)));
        Cout(ans);
        return 0;
    }
    sort(a,a+n);
    if(n%2==1){
        pos=a[n/2];
        ans+=abs(pos-a[0]);
        ll cntt=1;
        rep(i,n){
           ans+=abs(a[i]-a[n-i-1]);
           cntt++;
           if(cntt==n-1)break;
           cntt++;
           ans+=abs(a[n-i-1]-a[i+1]);
           if(cntt==n-1)break;
        }
        //Cout(ans);

        pos=a[n/2];
        cnt+=abs(pos-a[n-1]);
        cntt=1;
        rep(i,n){
           cnt+=abs(a[n-i-1]-a[i]);
           cntt++;
           if(cntt==n-1)break;
           cntt++;
           cnt+=abs(a[i]-a[n-i-2]);
           if(cntt==n-1)break;
        }
        //Cout(cnt);
        ans=max(ans,cnt);
    }
    else{
        pos=a[n/2-1];
        ans+=abs(pos-a[0]);
        ll cntt=1;
        rep(i,n){
            if(cntt==n-2){
                ans+=abs(a[i]-a[n/2+1]);
                break;
            }
           ans+=abs(a[i]-a[n-i-1]);
           cntt++;
           if(cntt==n-1)break;
           if(cntt==n-2){
                ans+=abs(a[n-i-1]-a[n/2+1]);
                break;
            }
            cntt++;
           ans+=abs(a[n-i-1]-a[i+1]);
           if(cntt==n-1)break;
        }
        //Cout(cnt);

        pos=a[n/2-1];
        cnt+=abs(pos-a[n-1]);
        cntt=1;
        rep(i,n){
           cnt+=abs(a[n-i-1]-a[i]);
           cntt++;
           if(cntt==n-1)break;
           cntt++;
           cnt+=abs(a[i]-a[n-i-2]);
           if(cntt==n-1)break;
        }
        //Cout(cnt);
        ans=max(ans,cnt);
        cnt=0;

        pos=a[n/2];
        cnt+=abs(pos-a[0]);
        //Cout(cnt);
        cntt=1;
        rep(i,n){
           cnt+=abs(a[i]-a[n-i-1]);
           //Cout(cnt);
           cntt++;
           if(cntt==n-1)break;
            cntt++;
           cnt+=abs(a[n-i-1]-a[i+1]);
           //Cout(cnt);
           if(cntt==n-1)break;
           //Cout(cnt);
        }
        //Cout(cnt);
        ans=max(ans,cnt);
        cnt=0;

        pos=a[n/2+1];
        cnt+=abs(pos-a[n-1]);
        cntt=1;
        rep(i,n){
            if(cntt==n-2){
                cnt+=abs(a[n-i-1]-a[n/2]);
                break;
            }
           cnt+=abs(a[n-i-1]-a[i]);
           cntt++;
           if(cntt==n-1)break;
           if(cntt==n-2){
                cnt+=abs(a[i]-a[n/2]);
                break;
            }
           cntt++;
           cnt+=abs(a[i]-a[n-i-2]);
           if(cntt==n-1)break;
        }
        //Cout(cnt);
        ans=max(ans,cnt);
    }
    Cout(ans);
    return 0;
}
