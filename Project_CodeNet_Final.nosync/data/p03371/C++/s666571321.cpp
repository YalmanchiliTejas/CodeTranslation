#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ansab=0;
  ll ansabc=0;
  ll ansc=0;
  ansab=a*x+b*y;
  int mi=min(x,y);
  ansabc=mi*2*c;
  if(x>mi){
    ansabc+=(x-mi)*a;
  }else{
    ansabc+=(y-mi)*b;
  }
  int ma=max(x,y);
  ansc=ma*2*c;
  ll ansmi=min(ansab,ansabc);
  ll cal=min(ansmi,ansc);
  cout << cal << endl;
  return 0;
}
