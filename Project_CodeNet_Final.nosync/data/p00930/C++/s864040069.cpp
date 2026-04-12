#include<iostream>

using namespace std;

const int INF=1e9;

const int N_MAX=1<<20;
const int DAT_SIZE=N_MAX*2-1;
int dat[DAT_SIZE],lazy[DAT_SIZE];
int n;

void init(int size){
  fill(begin(dat),end(dat),INF);
  n=1;
  while(n<size){
    n*=2;
  }
}

void lazy_eval(int k){
  dat[k]+=lazy[k];
  if(k<n-1){
    lazy[k*2+1]+=lazy[k];
    lazy[k*2+2]+=lazy[k];
  }
  lazy[k]=0;
}

int rangemin(int a,int b,int k,int l,int r){
  if(r<=a||b<=l)return INF;
  lazy_eval(k);
  if(a<=l&&r<=b){
    return dat[k];
  }else{
    int v1=rangemin(a,b,k*2+1,l,(l+r)/2);
    int v2=rangemin(a,b,k*2+2,(l+r)/2,r);
    return min(v1,v2);
  }
}

int rangeadd(int v,int a,int b,int k,int l,int r){
  if(r<=a||b<=l){
    lazy_eval(k);
    return dat[k];
  }else if(a<=l&&r<=b){
    lazy[k]+=v;
    lazy_eval(k);
    return dat[k];
  }else{
    lazy_eval(k);
    int v1=rangeadd(v,a,b,k*2+1,l,(l+r)/2);
    int v2=rangeadd(v,a,b,k*2+2,(l+r)/2,r);
    return dat[k]=min(v1,v2);
  }
}

void change(int x,int v,int k,int l,int r){
  lazy_eval(k);
  if(k<n-1){
    if(x<(l+r)/2){
      change(x,v,k*2+1,l,(l+r)/2);
    }else{
      change(x,v,k*2+2,(l+r)/2,r);
    }
    lazy_eval(k*2+1);
    lazy_eval(k*2+2);
    dat[k]=min(dat[k*2+1],dat[k*2+2]);
  }else{
    dat[k]=v;
  }
}

int main(){
  int N,Q;
  cin>>N>>Q;
  init(N);
  char s[323456];
  cin>>s;
  for(int i=0,c=0;i<N;i++){
    c+=(s[i]=='(')-(s[i]==')');
    change(i,c,0,0,n);
  }
  for(int i=0;i<n*2-1;i++){
    //    cout<<i<<' '<<dat[i]<<endl;
  }
  while(Q--){
    int q;
    cin>>q;
    q--;
    if(s[q]=='('){
      rangeadd(-2,q,N,0,0,n);
      int l=-1,h=N;
      while(h-l>1){
	int m=(l+h)/2;
	if(rangemin(m,m+1,0,0,n)==m+1){
	  l=m;
	}else{
	  h=m;
	}
      }
      cout<<h+1<<endl;
      rangeadd(2,h,N,0,0,n);
      s[q]=')';
      s[h]='(';
    }else{
      rangeadd(2,q,N,0,0,n);
      int l=-1,h=q;
      while(h-l>1){
	int m=(h+l)/2;
	if(rangemin(m,q+1,0,0,n)<=1){
	  l=m;
	}else{
	  h=m;
	}
      }
      // cout<<l<<' '<<h<<endl;
      // for(int i=0;i<N;i++){
      // 	cout<<i<<' '<<rangemin(i,i+1,0,0,n)<<endl;
      // }
      // cout<<l<<' '<<h<<' '<<q<<endl;
      // cout<<rangemin(l,q+1,0,0,n)<<endl;
      // cout<<rangemin(h,q+1,0,0,n)<<endl;
      cout<<h+1<<endl;
      rangeadd(-2,h,N,0,0,n);
      s[q]='(';
      s[h]=')';
    }
    //cerr<<s<<endl;
  }
}