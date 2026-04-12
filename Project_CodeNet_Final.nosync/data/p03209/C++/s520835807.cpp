#include <iostream>
 
int n;
long long x;
long long a[55],p[55];
 
long long dfs(int i,long long sum){
  if(sum<=0)
    return 0;
  else if(i==0)
    return 1;
  else if(sum<=1+a[i-1])
    return dfs(i-1,sum-1);
  else if(sum==2+a[i-1])
    return p[i-1]+1;
  else if(sum<=2+2*a[i-1])
    return p[i-1]+1+dfs(i-1,sum-1-a[i-1]-1);
  else if(sum==3+2*a[i-1])
    return 2*p[i-1]+1;
}
 
int main(){
  std::cin>>n>>x;
  a[0]=1;
  p[0]=1;
  for(int i=1;i<=n;++i){
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  std::cout<<dfs(n,x)<<std::endl;
  return 0;
}
