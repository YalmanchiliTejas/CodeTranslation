#include<bits/stdc++.h>
using namespace std;
int n,d[1<<19],i,j,k,l,p[1<<19],x,y;
bool f;
main(){
  for(cin>>n;i<n;p[i]++,p[i+d[i]/10]--,++i)cin>>d[i];
  for(;j<n;x<1?f=1:0)x+=p[j++];
  fill(p,p+n,0);
  for(reverse(d,d+n);k<n;p[k]++,p[k+d[k]/10]--,++k);
  for(;l<n;y<1?f=1:0)y+=p[l++];
  cout<<(f?"no\n":"yes\n");
}