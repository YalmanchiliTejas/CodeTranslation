#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

typedef long long ll;

struct data{
  string name;
  int hyou;
  bool fav;
  data(const char *nm, int hy) :
    name(nm), hyou(hy), fav(false) {}
};

bool operator < (const data &lhs, const data &rhs){
  if(lhs.hyou != rhs.hyou)
    return lhs.hyou > rhs.hyou;
  return lhs.name < rhs.name;
}

int main(){
  int n, m, k, l;

  while(scanf("%d%d%d%d", &n, &m, &k, &l),
        n + m + k + l){
    vector<data> v; v.reserve(n);
    map<string, int> memo;
    vector<int> favs(m);
    REP(i,n){
      char buff[200]; int h;
      scanf("%s%d", buff, &h);
      v.push_back(data(buff, h));
    }

    sort(v.begin(), v.end());

    REP(i,n)
      memo[v[i].name] = i;

    REP(i,m){
      char buff[200];
      scanf("%s", buff);
      favs[i] = memo[buff];
      v[favs[i]].fav = true;
    }

    sort(favs.begin(), favs.end());

    int low  = 0;
    int high = min(m, k);

    while(low <= high){
      int mid = (low + high) / 2;
      bool ok = false;

      int cnt = 0;
      int i;
      for(i = 0; i < n; i++){
        if(k - i <= mid - cnt && !v[i].fav) break;
        if(v[i].fav) cnt++;
      }

      if(i == n){
        ok = true;
      }else{
        const data &border = v[i];

        ll need = 0;

        REP(j,mid){
          int id = favs[j];
          if(id <= i) continue;
          const data &now = v[id];
          if(now.name < border.name){
            need += border.hyou - now.hyou;
          }else{
            need += border.hyou - now.hyou + 1;
          }
        }

        if(need <= l) ok = true;
        //printf("%d: %d (%d) %lld\n", mid, ok, i, need);
      }

      if(ok){
        low  = mid + 1;
      }else{
        high = mid - 1;
      }
    }

    printf("%d\n", high);
  }

  return 0;
}