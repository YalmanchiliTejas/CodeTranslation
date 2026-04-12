#include <cstdio>
#include <numeric>
#include <iostream>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int main(){
  while(true){
    vector<int> n(6);
    REP(i,6) cin >> n[i];

    if(accumulate(n.begin(), n.end(), 0) == 0) break;

    int num = 100000001;
    REP(i,3) num = min(num, n[i]+n[3+i]);

    int ans = 0;

    REP(i,min(num+1, 3)){
      int tmp = i;
      REP(j,3){
	int a = n[j];
	int b = n[3+j];
	tmp += (a + b - i) / 3;
      }
      //printf("%d: %d\n", i, tmp);
      ans = max(ans, tmp);
    }

    cout << ans << endl;
  }
  return 0;
}