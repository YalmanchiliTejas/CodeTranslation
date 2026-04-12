#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

// ??????2?????¢?´¢??¨??§?????¢????£??????¨?????£???(?°???????)

struct query{int q,s,t;};

int n;
int a,d;
int m;
query ql[252521];
int k;

int main(){
  scanf("%d",&n);
  scanf("%d%d",&a,&d);
  scanf("%d",&m);
  REP(i,m){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    --y; --z;
    ql[i] = (query){x,y,z};
  }
  scanf("%d",&k);
  --k;
  // ???????????????
  int pos = k;
  REP(_i,m){
    int i = m-1-_i;
    query q = ql[i];
    if(q.q != 0)continue;
    int beg = q.s;
    int end = q.t;
    if(!(beg<=pos && pos<=end))continue;
    // ?????¢
    int len = end-beg+1;
    if(len%2==0){
      int len2 = len/2;
      pos -= beg;
      pos -= len2;
      if(pos>=0)++pos;
      pos = -pos;
      if(pos>=0)--pos;
      pos += len2;
      pos += beg;
    }else{
      int len2 = len/2;
      pos -= beg;
      pos -= len2;
      pos = -pos;
      pos += len2;
      pos += beg;
    }
  }
  int val = a+pos*d;
  REP(i,m){
    query q = ql[i];
    int beg = q.s;
    int end = q.t;
    if(!(beg<=pos && pos<=end))continue;
    if(q.q == 0){
      int len = end-beg+1;
      if(len%2==0){
        int len2 = len/2;
        pos -= beg;
        pos -= len2;
        if(pos>=0)++pos;
        pos = -pos;
        if(pos>0)--pos;
        pos += len2;
        pos += beg;
      }else{
        int len2 = len/2;
        pos -= beg;
        pos -= len2;
        pos = -pos;
        pos += len2;
        pos += beg;
      }
    }else if(q.q == 1){
      val += 1;
    }else if(q.q == 2){
      val /= 2;
    }
  }
  cout<<val<<endl;
  return 0;
}