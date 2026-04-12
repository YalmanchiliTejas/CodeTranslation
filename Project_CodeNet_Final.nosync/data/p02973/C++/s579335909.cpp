#include<bits/stdc++.h>
using namespace std;
#define ing long long 

signed main(void){
  int N; cin >> N;
  multiset<int> ms;
  for(int i = 0; i < N; i++){ 
    int a; cin >> a;
    //aより小さなものがなければ、そのまま入れる
    if( ms.empty() || *ms.begin() >= a ){ 
      ms.insert(a);
    }
    else{ // aより小さなものがある
      
      auto itr = ms.lower_bound(a);
      itr--;
      ms.erase(itr);
      ms.insert(a);
    }
  }
  
  cout << ms.size() << endl;
  
  return 0;
}
  