#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin>>H.at(i);
  }
  int count = N;/*見える数を条件を満たす度に減らしていく*/
  for(int i=1;i<N;i++){/*2番目からスタート*/
    for(int j=i-1;j>=0;j--){/*(i+1)番目までの山の高さを(i+1)番目の山と比較*/
      if(H.at(i)<H.at(j)){/*自分より高い山があった時点でその山からは海は見えないのでbreak;*/
        count--;
        break;
      }
    }
  }
  cout<<count<<endl;
  return 0;
}
