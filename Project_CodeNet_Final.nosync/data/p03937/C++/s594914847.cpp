#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
//#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;

char M[10][10];

int main(){
  int h,w;
  cin>>h>>w;
  rep(i,h)rep(j,w)cin>>M[i][j];

  int sum=0;
  rep(i,h)rep(j,w){
    if(M[i][j]=='#'){
      sum++;
      M[i][j]='.';
    }
  }
  cout<<(sum==h+w-1?"Possible":"Impossible")<<endl;
  return 0;
}
