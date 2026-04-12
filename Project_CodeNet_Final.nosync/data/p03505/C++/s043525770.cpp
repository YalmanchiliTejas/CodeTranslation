#include<bits/stdc++.h>
using namespace std;

using Int = __int128_t;
Int abs128(Int val){return val<0?-val:val;}

ostream &operator<<(ostream &os,Int val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    Int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,Int &val){
  string s;
  is>>s;
  val=0;
  for(Int i=0;i<(Int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}



signed main(){
  Int k,a,b;
  cin>>k>>a>>b;
  if(a>=k){
    cout<<1<<endl;
    return 0;
  }
  if(a<=b){
    cout<<-1<<endl;
    return 0;
  }
  Int l=0,r=1e22;
  while(l+1<r){
    Int m=(l+r)>>1;
    if((m+1)*a-m*b>=k) r=m;
    else l=m;
  }
  cout<<2*r+1<<endl;
  return 0;
}
