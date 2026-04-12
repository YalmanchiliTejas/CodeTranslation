#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);
#define H 11
#define N 110
ll d[H][H],z[N][N],h,w;
int main(){
  cin>>h>>w;
  for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
    cin>>d[i][j];
  }
  for(int i=0;i<N;i++)for(int j=0;j<N;j++){
    z[i][j]=0;
    for(int a=1;a<=h;a++)for(int b=1;b<=w;b++){
      chmax(z[i][j],d[a][b]-i*a-j*b);
    }
  }
  bool ok=1; ll cnt=0;
  for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
    ll mi=1e9;
    for(int a=0;a<N;a++)for(int b=0;b<N;b++){
      if(z[a][b]>100)continue; cnt++;
      chmin(mi,z[a][b]+a*i+b*j);
    }
    if(mi!=d[i][j])ok=0;
  }
  cnt=cnt/h/w+2*(N-1);
  if(ok==0){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  cout<<2*N<<" "<<cnt<<endl;
  for(int i=1;i<N;i++)cout<<i<<" "<<i+1<<" X"<<endl;
  for(int i=N+1;i<2*N;i++)cout<<i<<" "<<i+1<<" Y"<<endl;
  for(int a=0;a<N;a++)for(int b=0;b<N;b++){
    if(z[a][b]>100)continue;
    cout<<a+1<<" "<<2*N-b<<" "<<z[a][b]<<endl;
  }
  cout<<1<<" "<<2*N<<endl;
    return 0;
}

