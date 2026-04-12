#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
  int g=0,h,i;
  int n;
  for(;;){
    cin>>n;
    if(n==0)
      break;
    vector<int> p;
    vector<string> s;
    for(i=0;i<n;i++){
      string str;
      int k,m,h;
      cin>>str>>k>>m>>h;
      s.push_back(str);
      p.push_back(k*3+h);
    }
    do{
      h=0;
      for(i=1;i<n;i++){
	if(p[i-1]<p[i]){
	  swap(p[i-1],p[i]);
	  swap(s[i-1],s[i]);
	  h=1;
	}
      }
    }while(h);
    if(g)
      cout<<endl;
    g=1;
    for(i=0;i<n;i++)
      cout<<s[i]<<","<<p[i]<<endl;
  }
  return 0;
}