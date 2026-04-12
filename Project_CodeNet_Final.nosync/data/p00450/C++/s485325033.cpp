#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;

int N;
vector<P>stone;

int main(){
  while(scanf("%d",&N) && N){
    stone.clear();
    int c;
    for(int i=1;i<=N;i++){
      scanf("%d",&c);
      if(i&1){
	if(stone.empty() || stone[stone.size()-1].second != c) stone.push_back(P(1, c));
	else stone[stone.size()-1].first += 1;
      }else{
	if(stone[stone.size()-1].second == c) stone[stone.size()-1].first += 1;
	else{
	  stone[stone.size()-1] = P(stone[stone.size()-1].first+1, c);
	  if(stone.size()>1 && stone[stone.size()-2].second == c){
	    stone[stone.size()-2].first += stone[stone.size()-1].first;
	    stone.pop_back();
	  }
	}
      }
    }

    int res = 0;
    for(int i=0;i<stone.size();i++) if(stone[i].second == 0) res += stone[i].first;
    printf("%d\n", res);
  }
  return 0;
}