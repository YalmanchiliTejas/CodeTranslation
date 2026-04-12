/*
    This is the solution from syr.
    OJ:
    ProblemID:
    Date:
    Status:Unknown
*/
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

using namespace std;

const int debug=0;
const int INF=1e9+7;

int n,k;
long long ans;

int main(){
	scanf("%d%d",&n,&k);
	if(k==0){
		printf("%lld\n",(long long)n*n);
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		int x=n-(n%i);
		ans+=(long long)x/i*(i-k);
//		printf("%lld %lld\n",(long long)x/i*(i-k),max((long long)0,(long long)(n%i)-k+1));
		ans+=max((long long)0,(long long)(n%i)-k+1);
	}
	printf("%lld\n",ans);
	return 0;
}

/*
Sample Input
*/
