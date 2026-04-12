#include <bits/stdc++.h>
#include <map> // pair
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  int ans=0;
  for(int i=0;i<N;i++){
    cin>>H.at(i);
    int flag = 0;
    for(int j=0;j<i;j++){
      if(H.at(j)>H.at(i))flag++;
    }
    if(flag==0)ans++;
    flag=0;
  }
  cout<<ans<<endl;
  }
