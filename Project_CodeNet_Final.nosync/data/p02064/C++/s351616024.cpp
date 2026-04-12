#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N,S,T;

int sdis[303];
int tdis[303];

const int INF=2e9;

int main(){
  cin>>N>>S>>T;
  
  for(int i=1;i<=N;i++){
      if(i==S) continue;
      cout<<"? "<<S<<" "<<i<<endl;
      int x;
      cin>>x;
      sdis[i]=x;
  }
  for(int i=1;i<=N;i++){
      if(i==T) continue;
      if(i==S){
          tdis[S]=sdis[T];
      }else{
          cout<<"? "<<T<<" "<<i<<endl;
          int x;
          cin>>x;
          tdis[i]=x;
      }
  }

  int now=S;
  vector<int> ans;
  ans.push_back(S);
  while(S!=T){
      int nex;
      int mi=INF;
      for(int i=1;i<=N;i++){
          if(sdis[now]<sdis[i]&&tdis[now]>tdis[i]){
              int a=sdis[i]-sdis[now];
              int b=tdis[now]-tdis[i];
              if(a==b){
                  if(mi>a){
                      nex=i;
                      mi=a;
                  }
              }
          }
      }
      ans.push_back(nex);
      if(nex==T) break;
      now=nex;
  }

  cout<<"!";
  for(int i=0;i<ans.size();i++) cout<<" "<<ans[i];
  cout<<endl;

  return 0;
}

