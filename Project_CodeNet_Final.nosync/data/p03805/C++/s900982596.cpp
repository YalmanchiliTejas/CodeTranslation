#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
typedef long long ll;

int N,M;
int a[28],b[28];

int main(){
  scanf("%d %d",&N,&M);
  rep(i,M){
    scanf("%d %d",&a[i],&b[i]);
  }
  vector<int> v(N);
  rep(i,N){
    v[i]=i+1;
  }
  ll count=0;
  do{
    if(v[0]==2)break;
    int vcount=0;
    rep(i,N-1){
      rep(j,M){
        if((v[i]==a[j]&&v[i+1]==b[j])||(v[i]==b[j]&&v[i+1]==a[j])){
          vcount++;
          if(vcount==N-1){
            count++;
          }
        }
      }
    }
  
  }while(next_permutation(v.begin(),v.end()));
  printf("%lld",count);
  
}
