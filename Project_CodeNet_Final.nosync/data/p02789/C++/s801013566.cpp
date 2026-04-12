#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795

int main(void)
{
	int n, m;

	while(scanf("%d%d", &n, &m)==2)
	{
		bool ans=(m==n);

		printf("%s\n", ans?"Yes":"No");
	}
	return 0;
}
