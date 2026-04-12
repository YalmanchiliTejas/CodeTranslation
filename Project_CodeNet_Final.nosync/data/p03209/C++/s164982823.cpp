#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//a->bread p->meat

long long f(long long N,long long X,vector<long long> a,vector<long long> p) {
	if (N==0) {
    if(X<=0){
      return 0;
    }
		else{
      return 1;
    }}
  else if(X<=(1+a[N-1])){
    return f(N-1,X-1,a,p);
  }
  else{
    return p[N-1]+1+f(N-1,X-2-a[N-1],a,p);
  }
	}

int main(){
  long long N,X,ans;
  cin>>N>>X;
  vector<long long> a;
  vector<long long> p;
  a.push_back(1);
  p.push_back(1);
  long long a_tmp,p_tmp;
  a_tmp=1;
  p_tmp=1;
  for(int i=0;i<60;++i){
    a_tmp=a_tmp*2+3;
    p_tmp=p_tmp*2+1;
    a.push_back(a_tmp);
    p.push_back(p_tmp);
  }
  ans=f(N,X,a,p);
  cout<<ans;
  return 0;
  }