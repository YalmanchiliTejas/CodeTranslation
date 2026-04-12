#include<bits/stdc++.h>
#define fi first
#define se second
#define show(x) cout<<#x<<"="<<x<<"\n"
typedef long long ll;
template<typename T>
void print_to(std::ostream &os,const char *,const char *tail,const T &fst){
  os<<fst<<tail;
}
template<typename Fst,typename... Rst>
void print_to(std::ostream &os,const char *del,const char *tail,const Fst &fst,const Rst &... rst){
  os<<fst<<del;
  print_to(os,del,tail,rst...);
}
template<typename Iter>
void print_to_(std::ostream &os,const char *del,const char *tail,Iter bgn,Iter end){
  for(Iter it=bgn;it!=end;){
    os<<*it;
    if(++it!=end)os<<del;
    else os<<tail;
  }
}
template<typename Fst,typename... Rst>
void println(const Fst &fst,const Rst &... rst){
  print_to(std::cout,"\n","\n",fst,rst...);
}
template<typename Fst,typename... Rst>
void print(const Fst &fst,const Rst &... rst){
  print_to(std::cout," ","\n",fst,rst...);
}
template<typename Iter>
void println_(Iter bgn,Iter end){
  print_to_(std::cout," ","\n",bgn,end);
}
using namespace std;
//const int MOD=(ll)1e10+7;
const int dy[]={1,0,-1};
const int dx[]={1,0,-1};
ll n,m,h,w;
string s;
ll dp[6][2][100000];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
  FILE *stream1;
  //FILE *stream2;
  stream1=freopen("in","r",stdin);
  //stream2=freopen("out","w",stdout);
  if(stream1==NULL)return 0;
  //if(stream2==NULL)return 0;
#endif
  ll k;cin>>n>>k;
  ll sum=0;
  for(ll b=k+1;b<=n;b++){
    if(n%b==0){
      sum+=(b-k)*(n/b);
    }else{
      sum+=(b-k)*(n/b);
      if(n%b-k>=0){
        if(k!=0)sum+=(n%b-k+1);
        else sum+=(n%b-k);
        //if(n%b-k==0)sum+=1;
      }
    }
    //show(sum);
  }
  cout<<sum<<endl;
#ifdef LOCAL_DEFINE
  cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
  fclose(stream1);
  //fclose(stream2);
#endif
    return 0;
}




