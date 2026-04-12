#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;
 
int main()
{
int m,n,i;
set<int> player;
set<int>::iterator it;
string s,right;
stringstream ss;
while(cin>>m>>n,m|n){
 player.clear();
 for(i=1;i<=m;i++)player.insert(i);
 it=player.begin();
 
 for(i=1;i<=n;i++){
  cin>>s;
  if(player.size()==1)continue;
  right="";
  if(i%3&&i%5){
   ss.str("");
   ss<<i;
   right=ss.str();
  }else{
   if(!(i%3))right+="Fizz";
   if(!(i%5))right+="Buzz";
  }
  if(s!=right)player.erase(it++);
  else it++;
  if(it==player.end())it=player.begin();
 }
 for(it=player.begin();it!=player.end();it++){
  if(it!=player.begin())cout<<" ";
  cout<<*it;
 }
 cout<<endl;
}
}