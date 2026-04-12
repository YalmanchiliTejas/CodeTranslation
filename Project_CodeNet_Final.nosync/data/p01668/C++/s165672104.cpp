#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1000000007;
ll add(ll a,ll b){ return (a+b)%mod; }
ll mul(ll a,ll b){ return (a*b)%mod; }

ll mpow(ll a,ll b){
  if(b==0)return 1;
  ll res=mpow( mul(a,a) , b/2 );
  if(b&1)res=mul(res,a);
  return res;
}

string A,B,C;

ll L[100000];
int solve(string &s){
  int n=s.size();
  int m=C.size();
  ll res=0;
  ll num=0;

  ll B=1;
  L[n]=0;
  for(int i=n-1;i>=0;i--){
    L[i]= add(L[i+1], B*(s[i]-'0') );
    B=mul(B,10);
  }
  
  for(int i=0;i+m<=n;i++){
    string tmp=s.substr(i,m);
    if( C < tmp ){

      if(C=="0")res=add(res,   mul(num,mpow(10,n-i-m))  );
      else res=add(res,   mul(num+1,mpow(10,n-i-m))  );
      
    }else if( C==tmp ){

      if(C=="0"){
        res=add(res,   mul( add(num,mod-1) , mpow(10,n-i-m))    );
        res=add(res,   L[i+m]+1  );
      }else{
        res=add(res,   mul(num, mpow(10,n-i-m))    );
        res=add(res,   L[i+m]+1  );
      }
      
    }else if( tmp < C ){

      res=add(res, mul(num,mpow(10,n-i-m) ) );
      
    }
    num=add( mul(num,10) , s[i]-'0');
  }

  if(C=="0")res=add(res,1);
  return res;
}

int main(){
  cin>>A>>B>>C;
  
  int ans=mod-solve(A);
  for(int i=0;i+(int)C.size()<=(int)A.size();i++){
    if(A.substr(i,C.size())==C)ans++;
  }
  ans+=solve(B);
  ans%=mod;
  cout<<ans<<endl;
  return 0;
}