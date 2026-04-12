#include<cstdio>
#include<vector>
#include<map>
#define F first
#define S second
using namespace std;
typedef pair<int, int> P;
int main(void){
  int n, m, ans = 0;
  bool x[100010];
  vector<P> v;
  for( ; ; ){
    scanf("%d", &n);
    if(!n) break;
    for(int i = 1;i <= n; i++){
      scanf("%d", &m);
      x[i] = m;
    }
    ans = 0; v.clear();
    v.push_back(make_pair(1, x[1]));
    for(int i = 2;i <= n; i++){
      if(x[i] == v.back().S) v.back().F++;
      else if(i % 2) v.push_back(make_pair(1, x[i]));
      else{
	m = v.back().F; v.pop_back();
	if(v.empty()) v.push_back(make_pair(m + 1, x[i]));
	else v.back().F += m + 1;
      }
    }
    for(int i = 0;i < v.size(); i++){
      if(!v[i].S) ans += v[i].F;
    }
    printf("%d\n", ans);
  }
}
