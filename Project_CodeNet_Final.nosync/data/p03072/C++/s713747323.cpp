typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#include <bits/stdc++.h>
using namespace std;






int main() {
  int N;
  cin>>N;
  int max=0;
  int count =0;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    if(max<=x){
      count++;
      max=x;
    }
  }
  cout<<count<<endl;
  
}