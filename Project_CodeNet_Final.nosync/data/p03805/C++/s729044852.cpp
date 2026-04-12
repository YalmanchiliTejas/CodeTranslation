#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(50),b(50);
  for(int i=0;i<M;i++)cin >> a[i] >> b[i];
  int ans=0;
  vector<int> q;
  for(int i=1;i<=N;i++)q.push_back(i);
  do{
    int count=0;
    for(int i=0;i<N-1;i++){
      bool w=false; 
      for(int j=0;j<M;j++){
        if(q[i]==a[j] && q[i+1]==b[j] || q[i]==b[j] && q[i+1]==a[j])w=true;
      }
      if(w){count++;}
    }
    if(count==N-1 && q[0]==1)ans++;
  }while(next_permutation(q.begin(),q.end()));
  cout << ans << endl;
}