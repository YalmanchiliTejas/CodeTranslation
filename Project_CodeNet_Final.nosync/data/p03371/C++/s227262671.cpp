//A - comes only from A's and AB's - 
//AB gives me better then I will buy there
//B - comes only from
//if half the charge is less than half tthe mine then non need of buying that
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  
  int na=0,nb=0,cost=0;
  
  if(c*2<=a){na=x;nb=x;cost=x*2*c;}
  if(c*2<=b){int rem = y-nb;nb+=(rem);na+=(rem);cost+=(rem)*2*c;}
 // cout<<na<<' '<<nb<<'\n';
  if(2*c<=(a+b)){int rem=min(x-na,y-nb);
  if(rem>=0){nb+=rem;na+=rem;cost+=2*c*rem;}}
 // cout<<na<<' '<<nb<<'\n';
  if(x-na>0)cost+=a*(x-na);
  if(y-nb>0)cost+=b*(y-nb);
  
  cout<<cost;
}