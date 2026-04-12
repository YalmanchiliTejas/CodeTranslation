#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 25
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
  scanf("%d",&head);
  RI(tail...);
}
using namespace std;
typedef long long LL;
int in[M];
int main()
{  
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> in[i];
	int ans = 1, cur = in[0];
	for(int i = 1; i < n; i++) if(in[i] >= cur){
		 cur = in[i];
		 ans++;
	}
	cout << ans << endl;
  return 0;
}
