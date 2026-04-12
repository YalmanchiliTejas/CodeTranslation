// author: vinoda
#include<bits/stdc++.h>
using namespace std;

long long sum[100008];
long long pos[100008];
bool visited[100008];

int main(){
  long long n,m;
  long long x;
  cin>>n>>x>>m;
  long long res=0, i=2;
  long long prev=x;
  visited[x]=true;
  pos[x]=1;
  sum[1]=x;

  if(n==1) res=x;
  else{
    while(true){
      long long cur=(prev*prev)%m;
      if(visited[cur]){
        long long curr_pos=pos[cur];
        long long cycle_sum=sum[i-1]-sum[curr_pos-1];
        long long rem=n-(curr_pos-1);
        long long cycle_size=i-curr_pos;
        long long d=rem/cycle_size;
        res+=(sum[curr_pos-1]+d*cycle_sum);
        long long excess=rem%cycle_size;
        if(excess) res+=(sum[excess+curr_pos-1]-sum[curr_pos-1]);
        break;
      }
      else{
        visited[cur]=true;
        pos[cur]=i;
        sum[i]=sum[i-1]+cur;
        ++i;
        prev=cur;
      }
      if(i>n){
        res=sum[i-1];
        break;
      }
    }
  }
  cout<<res<<endl;
}
