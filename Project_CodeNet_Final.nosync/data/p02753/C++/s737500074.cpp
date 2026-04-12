//organize and stay in moment - Abhinav IIIT-A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,n) for(int i=x;i<n;++i)
#define ar array
#define MAXN (int)2e5+5
#define pb push_back
int mod= 998244353;
int arr[MAXN];
int as;
void input(){
  cin>>as;
  f(i,0,as) cin>>arr[i];
}
void q1(){
  string s; cin>>s;
  int a=0,b=0;
  f(i,0,3)
  s[i]=='A'  ? ++a : ++b;
  if(a&&b)
    cout<<"Yes";
  else cout<<"No";
}
void q2(){
  int n,a,b;
  cin>>n>>a>>b;
  int t=a+b;
  int q=n/t;
  int ans=q*a;
  int r=n%t;
  ans+=min(r,a);
  cout<<ans;
}
void q3(){
  int a,b; cin>>a>>b;
  for(int i=1;i<=100000;++i){
    int x=i*8; x/=100;
    int y=i*10; y/=100;
    if(x==a && y==b){
      cout<<i;
      return ;
    }
  }
  cout<<-1;
}
void q4(){
  string s; cin>>s;
  deque<int> q;
  f(i,0,s.size())
  q.push_back(s[i]);
  int Q; cin>>Q;
  int curr=0;
  while(Q--){
    int t;
    cin>>t;
    if(t==1){
      curr=1-curr;
    }else{
      // 0 0 begin
      //0 1 end
      //1 0 end
      //1 1 begin
      int f;char c; cin>>f>>c;
      if((f+curr)%2==0)
        q.push_front(c);
      else q.push_back(c);
    }
  }
  string ret="";
  while(!q.empty()){
    ret+=q.front();
    q.pop_front();
  }
  if(curr)
     reverse(ret.begin(),ret.end());
   cout<<ret;
   return ;
}
void q5(){
  int n,p; cin>>n>>p;
  string s; cin>>s;
  int ans=0;
  if(p==2){
    f(i,0,n)
    if((s[i]-'0')%2==0)
      ans+=i+1;
  }else if(p==5){
    f(i,0,n)
    if((s[i]-'0')%5==0)
      ans+=i+1;
  }else {
    int tt=1;
    int curr=0;
     map<int,int> mp;
     mp[0]++;
     for(int i=n-1;i>=0;--i){
        curr+=(s[i]-'0')*tt;
        tt*=10;
        tt%=p; curr%=p;
        ans+=mp[curr];
        ++mp[curr];
     }
  }
  cout<<ans;
}
int mod2=998244353;
void solve(){
 
}
int32_t main()
{
  int t; t=1; //cin>>t;
  while(t--) q1();
  return 0;
}
