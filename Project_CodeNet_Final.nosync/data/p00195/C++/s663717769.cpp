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
	for(;;){
		int bestid;
		int best = -1;
		rep(i, 5){
			int a, b;
			scanf("%d%d", &a, &b);
			if(a==0 && b==0)
				goto end;
			a += b;
			if(best < a){
				bestid = i;
				best = a;
			}
		}
		printf("%c %d\n", bestid+'A', best);
	}
end:
	return 0;
}