#include<bits/stdc++.h>
using namespace std;
#define db(x){if(cond)cerr<<__LINE__<<" "<<#x<<" " <<x<<endl;}
#define rep(i,b)for(auto i=0;i<(b);++i)
#define fo(i,a,b)for(auto i=(a);i<=(b);++i)
#define ford(i,a,b)for(auto i=(a);i>=(b);--i)
#define vv vector
#define pb push_back
template<typename X>void MA(X&a,X b){a=max(a,b);}template<typename X>void MI(X&a,X b){a=min(a,b);}
template<typename X>void clr(X&x,int a){memset(x,a,sizeof(a));};typedef long long ll;typedef long double ld;
int cond=0,multi=0,gcj=0;
int A[(int)2e5+11];

void solve(){
  int N;cin>>N;
  rep(i,N)cin>>A[i];

  deque<int>B;
  rep(i,N){
    if(i%2==0)B.push_back(A[i]);
    else B.push_front(A[i]);
  }
  if(N%2==1)reverse(B.begin(),B.end());
  rep(i,N){
    if(i)cout<<" ";
    cout<<B[i];
  }
  cout<<"\n";

}

























































int main(int argc,char** argv){
  ios::sync_with_stdio(false),cin.tie(0),cond=argc>=2&&argv[1][0]=='q'?1<<30:0;
  cout.setf(ios::fixed),cout.precision(10);int t;if(multi||gcj)cin>>t;else t=1;
  fo(i,1,t){if(cond)cerr<<__LINE__<<" "<<i<<endl;if(gcj)cout<<"Case #"<<i<<": ";
    solve();
  }return 0;}


/*
stringstream io;
#define cin io
int init(){
  io<<1<<endl;
  int N=500000;
  io<<N<<" "<<N<<endl;
  fo(i,1,N-1)io<<i-1<<" ";io<<endl;
  fo(i,0,N-1)io<<i%2<<" ";io<<endl;
  fo(i,0,N-1)io<<(N-1-i)/2<<" ";io<<endl;

  return 0;
}
int xx=init();
*/
