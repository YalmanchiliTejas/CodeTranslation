#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;

int main()
{
	int n;
	scanf("%d", &n);
	
	stack<char> S[100];
	char tmp[128];
	while(scanf("%s", tmp), strcmp(tmp, "quit")){
		int x;
		scanf("%d", &x);
		--x;
		
		string cmd = tmp;
		if(cmd == "push"){
			char c;
			scanf(" %c", &c);
			S[x].push(c);
		}
		else if(cmd == "pop"){
			printf("%c\n", S[x].top());
			S[x].pop();
		}
		else{
			int y;
			scanf("%d", &y);
			--y;
			S[y].push(S[x].top());
			S[x].pop();
		}
	}
	return 0;
}