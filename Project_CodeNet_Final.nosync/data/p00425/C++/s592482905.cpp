#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct Dice{
  Int s[6];
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    //s[0]:top
    //s[1]:south
    //s[2]:east
    //s[3]:west
    //s[4]:north
    //s[5]:bottom
    Int b;
    if(c=='E'){
      b=s[0];
      s[0]=s[3];
      s[3]=s[5];
      s[5]=s[2];
      s[2]=b;
    }
    if(c=='W'){
      b=s[0];
      s[0]=s[2];
      s[2]=s[5];
      s[5]=s[3];
      s[3]=b;
    }
    if(c=='N'){
      b=s[0];
      s[0]=s[1];
      s[1]=s[5];
      s[5]=s[4];
      s[4]=b;
    }
    if(c=='S'){
      b=s[0];
      s[0]=s[4];
      s[4]=s[5];
      s[5]=s[1];
      s[1]=b;
    }
    
    // migi neji (not verified)
    if(c=='L'){
      b=s[1];
      s[1]=s[3];
      s[3]=s[4];
      s[4]=s[2];
      s[2]=b;
    }
    if(c=='R'){
      b=s[1];
      s[1]=s[2];
      s[2]=s[4];
      s[4]=s[3];
      s[3]=b;
    }
    
  }
  Int top() {
    return s[0];
  }
  Int hash(){
    Int res=0;
    for(Int i=0;i<6;i++) res=res*256+s[i];
    return res;
  }
};
vector<Dice> makeDices(Dice d){
  vector<Dice> res;
  for(Int i=0;i<6;i++){
    Dice t(d);
    if(i==1) t.roll('N'); 
    if(i==2) t.roll('S'); 
    if(i==3) t.roll('S'),t.roll('S');
    if(i==4) t.roll('L'); 
    if(i==5) t.roll('R'); 
    for(Int k=0;k<4;k++){
      res.push_back(t);
      t.roll('E');
    }
  }
  return res;
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  while(cin>>n,n){
    Dice d;
    for(Int i=0;i<6;i++) d.s[i]=i+1;

    Int ans=d.top();
    for(Int i=0;i<n;i++){
      string s;
      cin>>s;
      d.roll(s[0]);
      ans+=d.top();
    }
    cout<<ans<<endl;
  }
  
  return 0;
}

