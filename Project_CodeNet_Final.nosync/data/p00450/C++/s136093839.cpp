#include<vector>
#include<iostream>
using namespace std;

#define REP(i,a,b) for(i=a; i<b; ++i)
#define rep(i,n) REP(i,0,n)

struct range{
  int start,end,color;
  range() {;}
  range(int start,int end,int color) : start(start), end(end), color(color) {;}
};

int main() {
  int n,i,j,k;
  ios_base::sync_with_stdio(false);
  while(cin>>n, n) {
    vector<range> stones;
    rep(i,n) {
      cin>>j;
      if(stones.empty()) stones.push_back(range(i+1,i+1,j));
      else if(i%2==0) {
	if(j == stones.back().color) stones.back().end++;
	else stones.push_back(range(i+1,i+1,j));
      }else{
	if(stones.back().color == j) stones.back().end++;
	else {
	  int st = i+1;
	  while(!stones.empty()) {
	    if(stones.back().color == j) {
	      stones.push_back(range(st,i+1,j));
	      break;
	    }else{
	      st = stones.back().start;
	      stones.pop_back();
	    }
	  }
	  if(stones.empty()) stones.push_back(range(1,i+1,j));
	}
      }
    }

    int ans = 0;
    rep(i,stones.size()) {
      if(stones[i].color == 0) {
	//cout<<stones[i].start<<" "<<stones[i].end<<" "<<stones[i].color<<endl;
	ans += stones[i].end - stones[i].start + 1;
      }
    }
    cout<<ans<<endl;
  }
}