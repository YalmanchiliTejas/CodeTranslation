//00
#include<vector>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
  for(int m,n;cin>>m>>n,m|n;){
    vector<int> v(m);
    for(int i=0;i<m;i++){
      v[i]=i+1;
    }
    int p=0;
    for(int i=1;i<=n;i++){
      string s;
      cin>>s;
      if(v.size()>1){
	bool f;
	if(i%15==0){
	  f=s=="FizzBuzz";
	}else if(i%3==0){
	  f=s=="Fizz";
	}else if(i%5==0){
	  f=s=="Buzz";
	}else{
	  f=atoi(s.c_str())==i;
	}
	if(f){
	  p=(p+1)%v.size();
	}else{
	  v.erase(v.begin()+p);
	  p=p%v.size();
	}
      }
    }
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<((i==v.size()-1)?'\n':' ');
    }
  }
  return 0;
}