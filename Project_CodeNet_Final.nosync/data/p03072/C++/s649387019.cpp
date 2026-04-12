#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int N;
  cin>>N;
  int H[N];
  rep(i,N)
    cin>>H[i];
  int count=0;
  for(int i=N-1;i>=0;i--){
    bool flag=true;
    for(int j=i-1;j>=0;j--){
      if(H[i]<H[j])
	flag=false;
    }
    if(flag)
      count++;
  }
  cout<<count<<endl;
  return 0;
}
  
