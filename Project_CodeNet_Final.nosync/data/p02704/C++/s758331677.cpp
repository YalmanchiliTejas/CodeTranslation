#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE

const int MAX = 505;
using ull = unsigned long long;
ull O[MAX][MAX]={};
ull Z[MAX][MAX]={};
ull A[MAX][MAX]={};

void drop(){
  cout<<-1<<newl;
  exit(0);
}

void answer(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j) cout<<' ';
      cout<<A[i][j];
    }
    cout<<newl;
  }
  exit(0);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<ull> ss(n),ts(n),us(n),vs(n);
  for(int i=0;i<n;i++) cin>>ss[i];
  for(int i=0;i<n;i++) cin>>ts[i];
  for(int i=0;i<n;i++) cin>>us[i];
  for(int i=0;i<n;i++) cin>>vs[i];

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(ss[i]==0) O[i][j]|= us[i];
      if(ss[i]==1) Z[i][j]|=~us[i];
      if(ts[j]==0) O[i][j]|= vs[j];
      if(ts[j]==1) Z[i][j]|=~vs[j];
    }
  }

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(O[i][j] & Z[i][j]) drop();

  for(int k=0;k<64;k++){
    auto setbit=[&](int i,int j){A[i][j]|=1ull<<k;};

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(ss[i]==0 and  (us[i]>>k)&1) setbit(i,j);
        if(ts[j]==0 and  (vs[j]>>k)&1) setbit(i,j);
      }
    }

    int h00=0,h01=0,h10=0,h11=0;
    int w00=0,w01=0,w10=0,w11=0;
    for(int i=0;i<n;i++){
      if(ss[i]==0 and ~(us[i]>>k)&1) h00++;
      if(ss[i]==0 and  (us[i]>>k)&1) h01++;
      if(ss[i]==1 and ~(us[i]>>k)&1) h10++;
      if(ss[i]==1 and  (us[i]>>k)&1) h11++;

      if(ts[i]==0 and ~(vs[i]>>k)&1) w00++;
      if(ts[i]==0 and  (vs[i]>>k)&1) w01++;
      if(ts[i]==1 and ~(vs[i]>>k)&1) w10++;
      if(ts[i]==1 and  (vs[i]>>k)&1) w11++;
    }

    if(h00 and w00){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(ss[i]==0 and  (us[i]>>k)&1) continue;
          if(ss[i]==1 and ~(us[i]>>k)&1) continue;
          if(ts[j]==0 and  (vs[j]>>k)&1) continue;
          if(ts[j]==1 and ~(vs[j]>>k)&1) continue;

          if(ss[i]==1 and (us[i]>>k)&1) setbit(i,j);
          if(ts[j]==1 and (vs[j]>>k)&1) setbit(i,j);
        }
      }
      continue;
    }

    if(h11 and w11){
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(ss[i]==1 and (us[i]>>k)&1)
            if(ts[j]==1 and (vs[j]>>k)&1)
              setbit(i,j);
      continue;
    }

    if(h11>=2 and w00>=2){
      int fh=n,fw=n;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(ss[i]==1 and  (us[i]>>k)&1) chmin(fh,i);
          if(ts[j]==0 and ~(vs[j]>>k)&1) chmin(fw,j);

          if(ss[i]==1 and  (us[i]>>k)&1)
            if(ts[j]==0 and ~(vs[j]>>k)&1)
              if((i==fh) xor (j==fw)) setbit(i,j);
        }
      }
      continue;
    }

    if(h00>=2 and w11>=2){
      int fh=n,fw=n;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(ss[i]==0 and ~(us[i]>>k)&1) chmin(fh,i);
          if(ts[j]==1 and  (vs[j]>>k)&1) chmin(fw,j);

          if(ss[i]==0 and ~(us[i]>>k)&1)
            if(ts[j]==1 and  (vs[j]>>k)&1)
              if((i==fh) xor (j==fw)) setbit(i,j);
        }
      }
      continue;
    }

    if(h11 and w01) continue;
    if(h01 and w11) continue;

    if(h00 and w10){
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(ss[i]==0 and ~(us[i]>>k)&1)
            if(ts[j]==1 and  (vs[j]>>k)&1)
              setbit(i,j);
      continue;
    }

    if(h10 and w00){
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(ss[i]==1 and  (us[i]>>k)&1)
            if(ts[j]==0 and ~(vs[j]>>k)&1)
              setbit(i,j);
      continue;
    }

    if(h01) w11=0;
    if(h10) w00=0;
    if(w01) h11=0;
    if(w10) h00=0;

    if(!h00 and !h11 and !w00 and !w11) continue;

    drop();
  }

  for(int i=0;i<n;i++){
    ull val_and=~0ull,val_or=0ull;
    for(int j=0;j<n;j++){
      val_and &= A[i][j];
      val_or  |= A[i][j];
    }
    if(ss[i]==0) assert(val_and==us[i]);
    if(ss[i]==1) assert(val_or ==us[i]);
  }

  for(int j=0;j<n;j++){
    ull val_and=~0ull,val_or=0ull;
    for(int i=0;i<n;i++){
      val_and &= A[i][j];
      val_or  |= A[i][j];
    }
    if(ts[j]==0) assert(val_and==vs[j]);
    if(ts[j]==1) assert(val_or ==vs[j]);
  }

  answer(n);
  return 0;
}
