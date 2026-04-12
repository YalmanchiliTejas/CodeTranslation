#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> x(n),y(n);
  for(Int i=0;i<n;i++) cin>>x[i]>>y[i];
  const Int OFS = 1e9;
  for(Int i=0;i<n;i++) x[i]=x[i]*2+OFS,y[i]=y[i]*2+OFS;

  const Int R = 20;
  auto calc=
    [&](Int u,Int v)->Int{
      auto dist=
        [&](Int a,Int b,Int c,Int d)->Int{
          if((a/R)!=(c/R)&&(b/R)!=(d/R))
            return abs(a-c)+abs(b-d);
          
          if((a/R)==(c/R)&&(b/R)==(d/R))
            return abs(a-c)+abs(b-d);

          if((a/R)==(c/R)&&(b/R)!=(d/R))
            return abs(b-d)+min((a%R)+(c%R),(R-(a%R))+(R-(c%R)));
          
          if((a/R)!=(c/R)&&(b/R)==(d/R))
            return abs(a-c)+min((b%R)+(d%R),(R-(b%R))+(R-(d%R)));

          assert(0);
          return -1;
        };
      Int res=0;
      for(Int i=0;i<n;i++) chmax(res,dist(u,v,x[i],y[i]));
      //cout<<u<<" "<<v<<":"<<res<<endl;
      return res;
    };

  const Int C = 5;
  auto check=
    [&](Int u,Int v)->Int{
      Int res=1e18;
      Int s=u/R,t=v/R;
      for(Int a=-C;a<=C;a++){
        for(Int b=-C;b<=C;b++){
          for(Int k=0;k<R;k++){
            chmin(res,calc((s+a)*R+k,(t+b)*R));
            chmin(res,calc((s+a)*R  ,(t+b)*R+k));
          }          
        }        
      }              
      return res;
    };
  Int au=0,av=0;
  {
    vector<Int> u(n),v(n);
    for(Int i=0;i<n;i++) u[i]=x[i]+y[i],v[i]=x[i]-y[i];

    auto rect=[&](Int &a1,Int &b1,Int &c1,Int &d1,
                  Int a2,Int b2,Int c2,Int d2)->void{               
                chmax(a1,a2);
                chmin(b1,b2);
                chmax(c1,c2);
                chmin(d1,d2);
              };
    const Int INF = 1e18;
    
    auto check2=[&](Int m)->Int{
                  Int a1=-INF,b1=INF,c1=-INF,d1=INF;
                  for(Int i=0;i<n;i++)
                    rect(a1,b1,c1,d1,u[i]-m,u[i]+m,v[i]-m,v[i]+m);

                  if(a1<=b1&&c1<=d1) au=a1,av=c1;
                  
                  return a1<=b1&&c1<=d1;
                };
    
    Int l=0,r=1e15;
    while(l+1<r){
      Int m=(l+r)>>1;
      if(check2(m)) r=m;
      else l=m;
    }    
  }
  
  Int ax=(au+av)/2,ay=(au-av)/2;
  double ans=check(ax,ay);
  cout<<ans/2.0<<endl;
  return 0;
}

