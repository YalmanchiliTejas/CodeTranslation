#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cassert>
#include <map>
#include <memory>
#include <memory.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, string> chara;

chara cs[100010];
map<string, bool> id;
vector<chara> fav;
vector<chara> other;

int main(){
  ll N, M, L, K;
  while(cin >> N >> M >> K >> L && (N || M || L || K)){
    fav.clear();
    other.clear();
    id.clear();
    rep(i, N){
      cin >> cs[i].second >> cs[i].first;
      cs[i].first *= -1;
    }
    rep(i, M){
      string name;
      cin >> name;
      id[name] = true;
    }
    sort(cs, cs + N);
    rep(i, N){
      cs[i].first *= -1;
      if(id[cs[i].second]) fav.push_back(cs[i]);
      else other.push_back(cs[i]);
    }
    int a = other.size();
    int ub = min(M, K) + 1;
    int lb = 0;
    
    while(ub - lb > 1){
      int mb = (ub + lb) / 2;
      int rest = K - mb;
    
      if(rest >= a){
	lb = mb;
      }else{
	chara last = other[rest];
	
	ll need = 0;
	rep(i, mb){
	  if(last.second < fav[i].second){
	    need += max(last.first + 1 - fav[i].first, 0LL);
	  }else{
	    need += max(last.first - fav[i].first, 0LL);
	  }
	}
	if(need > L) ub = mb;
	else lb = mb;
      }
    }
    cout << lb << endl;
  }
  return 0;
}