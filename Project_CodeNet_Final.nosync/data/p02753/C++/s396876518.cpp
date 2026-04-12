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
	char s[3+2];
	while(scanf("%3[AB]\n", s)==1)
	{
		bool ans=false;
		if(s[0]!=s[1] || s[1]!=s[2]) ans=true;
		printf("%s\n", ans?"Yes":"No");
	}
	return 0;
}
