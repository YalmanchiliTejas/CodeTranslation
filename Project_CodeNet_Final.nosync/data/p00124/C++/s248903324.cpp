#include<iostream>
#include<map>
using namespace std;
int main(){
  int n,p=0;
  while(cin>>n,n){
    multimap<int,string,greater<int> >m;
    if(p)cout<<endl;
    p++;
    while(n--){
    string s;
    int a,b,c;  
    cin>>s>>a>>b>>c;
    a=a*3+c;
    m.insert( make_pair(a,s) );
    }
    for(multimap<int,string,greater<int> >::iterator it=m.begin();it!=m.end();it++){
      cout<<(*it).second<<','<<(*it).first<<endl;
      }
  }
}