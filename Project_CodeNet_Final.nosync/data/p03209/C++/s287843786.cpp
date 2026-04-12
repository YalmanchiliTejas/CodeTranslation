#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>

using namespace std;

long long f(int N,long long X, vector<long long>a, vector<long long>p){
  if(N==0&&X<=0)return 0;
  if(N==0&&X>0)return 1;
  if(N!=0){
    if(X<=1+a[N-1]){
      return f(N-1,X-1,a,p);
    }else{
      return p[N-1]+1+f(N-1,X-2-a[N-1],a,p);
    }
  }
}

int main() {
  int N;
  long long X;
  cin>>N>>X;
  vector<long long>a(N+1),p(N+1);
  a[0]=1;p[0]=1;
  for(int i=1;i<=N;i++){
    a[i]=a[i-1]*2+3;
    p[i]=p[i-1]*2+1;
  }
  cout<<f(N,X,a,p)<<endl;
}