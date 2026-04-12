#include <cstdio>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#define f first
#define s second
#define mp make_pair

using namespace std;

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m), n + m){
    vector<int> coins(n);
    vector<int> memo(m, -1);
    queue<int> que;
    vector<int> amount(1 << n, 0);

    REP(i,n) scanf("%d", &coins[i]);

    REP(i,1<<n){
      REP(j,n) if(i & (1 << j)){
	amount[i] += coins[j];
      }
    }

    memo[0] = 0;
    que.push(0);

    while(que.size()){
      int sum = que.front(); que.pop();
      int cnt = memo[sum];

      REP(i,1<<n){
	int s = sum + amount[i];
	
	if(s > m) continue;
	if(s == m){
	  printf("%d\n", cnt + 1);
	  goto end;
	}
	if(memo[s] == -1){
	  memo[s] = cnt + 1;
	  que.push(s);
	}
      }
    }
  end:;
  }
  return 0;
}