#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

bool used[5005][5005];
map<int,int> mp;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A[i];

  sort(A.begin(),A.end());

  for(int i=0;i<N;i++) mp[A[i]]=i+1;
  int ans=0;
  for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
          if(used[i][j]) continue;
          used[i][j]=1;
          int diff=A[j]-A[i];
          int now=A[j];
          int res=1;
          int pre=j;
          while(mp.count(now+diff)){
              int tar=mp[now+diff]-1;
              res++;
              now+=diff;
              used[pre][tar]=1;
              pre=tar;
          }
          ans=max(ans,res);
      }
  }


  cout<<ans+1<<endl;

  return 0;
}

