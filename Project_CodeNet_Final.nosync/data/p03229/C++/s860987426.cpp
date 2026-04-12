#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());

  int64_t ans= data.back()- data.at(0);
  for(int n=1,offset=1; n+2 <= N-1; n+=2,offset++){
    ans+= data.at(N-1- offset)   - data.at(offset-1);
    ans+= data.at(N-1-(offset-1))- data.at(offset);
  }
  if(N%2 != 0){
    ans+= max(data.at(N/2+ 1)- data.at(N/2), data.at(N/2)- data.at(N/2- 1));
  }

  cout << ans << endl;
}