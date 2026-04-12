#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string.h>
#define INF 2147483647
#define LLINF 9223372036854775807
using namespace std;
int main(){
	long long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	long long cnt=LLINF;
	if(c*2<=(a+b)){
		for(int i=min(x,y);i<=max(x,y);i++){
			long long ans=0;
			ans+=c*2*i;
			long long p=x;
			long long n=y;
			p-=i;
			n-=i;
			ans+=max(1LL*0,p)*a;
			ans+=max(1LL*0,n)*b;
			cnt=min(cnt,ans);
		}
		cout<<cnt;
		return 0;
	}
	cnt=0;
	cnt+=a*x+b*y;
	cout<<cnt;
	return 0;
}