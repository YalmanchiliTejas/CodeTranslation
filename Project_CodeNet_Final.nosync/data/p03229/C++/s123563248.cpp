#include<bits/stdc++.h>
using namespace std;
vector<int>x;
vector<int>y;
vector<int>vec;

int main(){
  int n;
  long long p=0,q=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    vec.push_back(a);
  }
  sort(vec.begin(),vec.end());
  int a=1,b=n-1;
  x.push_back(vec[0]);
  for(int i=0;i<n;i++){
    if(i%2==1){
      x.push_back(vec[a]);
      a++;
      if(a>b)break;
      x.push_back(vec[a]);
      a++;
    }
    else{
      x.push_back(vec[b]);
      b--;
      if(a>b)break;
      x.push_back(vec[b]);
      b--;
    }
    if(a>b)break;
  }
  a=0,b=n-2;
  y.push_back(vec[n-1]);
  for(int i=0;i<n;i++){
    if(i%2==0){
      y.push_back(vec[a]);
      a++;
      if(a>b)break;
      y.push_back(vec[a]);
      a++;
    }
    else{
      y.push_back(vec[b]);
      b--;
      if(a>b)break;
      y.push_back(vec[b]);
      b--;
    }
    if(a>b)break;
  }
  for(int i=1;i<n;i++){
    if(i==1)p+=abs(x[0]-x[1]);
    else{
      p+=abs(x[i-2]-x[i]);
    }
  }
  for(int i=1;i<n;i++){
    if(i==1)q+=abs(y[0]-y[1]);
    else{
      q+=abs(y[i-2]-y[i]);
    }
  }
  /*for(int i=0;i<n;i++){
    cout<<y[i]<<' ';
    }*/
  cout<<max(p,q)<<endl;
  return(0);
}
