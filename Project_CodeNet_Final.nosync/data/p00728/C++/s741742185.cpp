#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define INF 1e09

using namespace std;

int main(){
  int n;
  int total, maxim, minim;
  int tmp;
  while(cin >> n and n){
    total = 0; maxim = -INF; minim = INF;
    REP(i, n) { cin >> tmp; total += tmp; maxim = max(maxim, tmp); minim = min(minim, tmp); }
    total -= (maxim + minim);
    cout << total / (n - 2) << endl;
  }
  return 0;
}