
    // Your code here!
    #include <bits/stdc++.h>
 
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
typedef long long ll;
//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main(){
  int a,b,c,x,y,ans,minxy,minab,maxxy,maxab;
  
  cin>>a>>b>>c>>x>>y;
  maxxy=max(x,y);
  minxy=min(x,y);
  minab=min(a,b);
  maxab=max(a,b);
  
  if(2*c<=a){
      if(2*c<=b)ans=2*c*maxxy;
      else{
          if(x<y)ans=2*c*x+(y-x)*b;
          else ans=2*c*x;
      }
  }else if(2*c<=b){
      
          if(y<x)ans=2*c*y+(x-y)*a;
          else ans=2*c*y;
     
  }else if(2*c<=a+b){
      if(x<y)ans=2*c*minxy+b*(y-minxy);
      else ans=2*c*minxy+a*(x-minxy);//cout<<minxy<<endl;
      //cout<<1<<endl;
  }else{
      ans=a*x+b*y;
  }
  
  cout<<ans<<endl;
}

   
    

   

