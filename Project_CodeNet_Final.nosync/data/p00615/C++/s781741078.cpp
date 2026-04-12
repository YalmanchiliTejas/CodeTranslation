#include<iostream>
#include<set>
using namespace std;
int main()
{
 int n,m,i,t,max;
 set<int> s;
 set<int>::iterator it;
 while(cin>>n>>m,n|m){
  s.clear();
  for(i=0;i<n+m;i++){cin>>t;s.insert(t);}
  max=t=0;
  for(it=s.begin();it!=s.end();it++){
   if(max<*it-t)max=*it-t;
   t=*it;
  }
  cout<<max<<endl;
 }
}