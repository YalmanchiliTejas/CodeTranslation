#include<bits/stdc++.h>
using namespace std;
int main(){
  uint64_t n;
  uint64_t m,x;
  cin>>n>>x>>m;
  vector<int64_t> r(m,-1);
  vector<int64_t> sum(2,0);
  sum[1]=x;
  r[x]=1;
  int curr=2;
  uint64_t next=x*x%m;
  while(r[next]==-1){
    r[next]=curr;
    sum.push_back(sum[sum.size()-1]+next);
    next=next*next%m;
    curr++;
  }
  int roop_num=curr-r[next];
  uint64_t roop_sum=sum[curr-1]-sum[r[next]-1];
  if(n<curr){
    cout<<sum[n]<<endl;
    return 0;
  }
  uint64_t result=sum[r[next]-1];
  uint64_t i=r[next]-1+(n-r[next]+1)/roop_num*roop_num;
  result+=(n-r[next]+1)/roop_num*roop_sum;
  if(i<n){
    result+=sum[r[next]-1+n-i]-sum[r[next]-1];
  }
  cout<<result<<endl;
}
  