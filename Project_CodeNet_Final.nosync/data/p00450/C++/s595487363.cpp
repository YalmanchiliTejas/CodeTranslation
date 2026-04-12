#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

vector<int> linear(vector<int> stone){
	int n = stone.size();
	int state = 0;
	for(int i = n-2; i >= 0; i--){
		bool eq = (stone[i+1] == stone[i]);
		if(!eq && (state || i % 2 == 0)){
			stone[i] = !(stone[i]);
			state = 1;
		}else if(eq && (i % 2 != 0)){
			state = 0;
		}
	}
	return stone;
}
vector<int> wrong(vector<int> v){
	REP(i,v.size()){
		if(i % 2 == 1){
			for(int j = i - 1; j >= 0; j--){
				if(v[i] == v[j]) break;
				else v[j] = v[i];
			}
		}
	}
	return v;
}

int main(void){
  int n;
  while(cin>>n,n){
    if(n==0) break;
		vector<int> stone(n);
		REP(i,n)cin>>stone[i];
    /*
		if(linear(stone) != wrong(stone)){
      REP(i,n){cout<<stone[i]<<" ";} cout<<endl;
      cout<<"linear:"; REP(i,n){cout<<linear(stone)[i]<<" ";} cout<<endl;
      cout<<"wrong:"; REP(i,n){cout<<wrong(stone)[i]<<" ";} cout<<endl;
		}
    */
    /*
		//REP(i,n){cout<<stone[i]<<" ";} cout<<endl;
		vector<int> ans = linear(stone);
		int count = 0;
		REP(i,n)if(ans[i]==0)count++;
		//REP(i,n){cout<<ans[i]<<" ";} cout<<endl;
		cout<<count<<endl;
    */
    vector<int> comp;
    int last = -1;
    int ans = 0;
    REP(i,n){
      if(i % 2 == 1){
        comp.back() += 1;
        if(last != stone[i]){
          if(stone[i]==0) ans += comp.back();
          else ans -= comp.back() - 1;
          if(comp.size() >= 2){
            int t = comp.back();
            comp.pop_back();
            comp.back() += t;
          }
        }else{
          ans += (stone[i] == 0);
        }
      }else{
        if(last != stone[i]) {
          comp.push_back(1);
        }else{
          comp.back() += 1;
        }
        ans += (stone[i] == 0);
      }
      last = stone[i];
    }
    cout<<ans<<endl;
  }
  return 0;
}