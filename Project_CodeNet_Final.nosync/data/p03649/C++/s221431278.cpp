#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;
long long int n,cnt=0,ans=0,a[60],b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

bool check(){
  ll ma=0;
  rep(i,n){
    ma=max(ma,a[i]);
  }
  if(ma==n-1)return true;
  else return false;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      
      cin>>n;
      rep(i,n)cin>>a[i];
      while(1){
        if(check())break;
        sort(a,a+n);
        reverse(a,a+n);
        pos=a[0];
        a[0]-=(pos/n)*n;
        pos=pos/n;
        ans+=pos;
        rrep(i,1,n)a[i]+=pos;
        //rep(i,n)Cout(a[i]);
      }
      Cout(ans);
     

       
return 0;
}
