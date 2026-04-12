#include<bits/stdc++.h>
using namespace std;
typedef pair<int, bool> PIB;

int n, ans = 0;
vector<PIB> stones;
int main()
{
  while(true){
    cin >> n;
    if(!n)
      break;

    stones.clear();
    ans = 0;
    for(int i = 1; i <= n; i++){
      bool stone;
      cin >> stone;
      
      if(i % 2){
	if(i == 1 || (stones.end() - 1)->second != stone)
	  stones.push_back(make_pair(1, stone));
	else
	  (stones.end() - 1)->first++;
      }
      
      else{
	if((stones.end() - 1)->second != stone){
	  (stones.end() - 1)->second = stone;
	  if(stones.end() - 1 != stones.begin()){
	    (stones.end() - 2)->first += (stones.end() - 1)->first;
	    stones.erase(stones.end() - 1);
	  }
	}
	(stones.end() - 1)->first++;
      }
    }

    for(int i = 0; i < stones.size(); i++)
      if(!stones[i].second)
	ans += stones[i].first;
    
    cout << ans << endl;
  }
  return 0;
}