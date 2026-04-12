#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return -1;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    return max(X,Y);
  }
}

void chmax(int64_t a,int b){
  int D=MAX_N-1+b;
  seg[D]=a;
  while(D>0){
    D--;
    D/=2;
    seg[D]=max(seg[2*D+1],seg[2*D+2]);
  }
}

int main() {
  int N,Q;
  cin>>N>>Q;
  for(int i=1;i<=N;i++){
    int64_t a;
    cin>>a;
    chmax(a,i);
  }
  for(int i=0;i<Q;i++){
    int64_t a,b,c;
    cin>>a>>b>>c;
    if(a==1){
      chmax(c,b);
    }
    else if(a==2){
      cout<<qu(b,c+1,0,0,MAX_N)<<endl;
    }
    else{
      if(qu(b,N+1,0,0,MAX_N)<c){
        cout<<N+1<<endl;
      }
      else{
        int l=b,r=N+1;
        while(r-l>1){
          int D=(l+r)/2;
          if(qu(b,D,0,0,MAX_N)>=c){
            r=D;
          }
          else{
            l=D;
          }
        }
        cout<<l<<endl;
      }
    }
  }
}