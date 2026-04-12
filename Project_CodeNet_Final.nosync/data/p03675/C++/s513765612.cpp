#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 200005
#define INF 1000000007LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;


int main()
{
	int n;
	ll a;
	list<ll> A;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(i%2==0)A.push_back(a);
		else A.push_front(a);
	}
	if(n%2==1)reverse(A.begin(),A.end());
	for(list<ll>::iterator it=A.begin();it!=A.end();it++){
		if(it!=A.begin())printf(" ");
		printf("%lld",*it);
	}
	printf("\n");

	return 0;
}
