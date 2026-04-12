#include<iostream>
#include<map>
using namespace std;
int main(){
  long long n;
  long long x;
  long long MOD;
  cin>>n>>x>>MOD;
  
  map<long long,long long>mp;
  long long pre=x;
  long long sum=x;
  long long left,right;
  mp[x]=1;
  for(int i=2;i<=MOD&&i<=n;i++){
    pre=(pre*pre)%MOD;
    sum+=pre;
    if(mp[pre]==0){
      mp[pre]=i;
    }else{
      left=mp[pre];
      right=i;
      break;
    }
  }

  n-=right;
  long long temp=0;
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    long long pos=itr->second;
    if(left<=pos&&pos<right){
      temp+=itr->first;
    }
  }

  long long cnt=n/(right-left);
  sum+=temp*cnt;
  n%=(right-left);
  
  for(int i=0;i<n;i++){
    pre=(pre*pre)%MOD;
    sum+=pre;
  }
  cout<<sum<<endl;
  return(0);
}