#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  int num=A*100+B*10+C;
  string ans="NO";
  if(num%4==0)ans="YES";
  cout<<ans<<endl;
}