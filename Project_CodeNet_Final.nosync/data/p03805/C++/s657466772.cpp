#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 8;
int main()
{
  int n,m,a,b,i,res=0;
  int d[N_MAX][N_MAX],rr[N_MAX];
  bool f;
  cin >> n >> m;
  for(i=0;i<n;i++)
    fill(d[i],d[i]+n,0);
  for(i=0;i<m;i++){
    cin >> a >> b;
    d[a-1][b-1]=1;
    d[b-1][a-1]=1;
  }
  for(i=0;i<n;i++)
    rr[i]=i;
  do {
    f=0;
    for(i=1;i<n;i++)
      if(d[rr[i-1]][rr[i]]==0){
        f=1;
        break;
      }
    if(f==0)
      res++;
  } while(next_permutation(rr+1,rr+n));
  cout << res << endl;
  return 0;
}