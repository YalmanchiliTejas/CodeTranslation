//每一次操作：对总和-1
//总和充分大时
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
ll a[55];
int main(){
	int n;
	ll x,sum=0LL;
	scanf("%d",&n);
	rep(k,n){
		scanf("%lld",&a[k]);
		sum+=a[k];
	}
	ll ap=0LL;
	multiset<ll> St;
	//Ai-P*n+max(0,(S-(ap+P)-(Ai-P*n)-(n-1)*(n-1))/2)<n
	//Ai-n<n*P and 2*Ai-2*P*n+S-(ap+P)-(Ai-P*n)-(n-1)*(n-1)<2*n Ai+S-ap-n*n-1<(n+1)P
	//P=max((a[k]+ap)/n,(a[k]+S-n*n-1))
	rep(k,n){
		ll P=max((a[k]+ap)/n,(sum+a[k]-n*n-1)/(n+1));
		ap+=P;
		a[k]-=P*(n+1);
		St.insert(a[k]);
	}
	while(*(St.rbegin())>=ll(n)-ap){
		ll out=*(St.rbegin());
		St.erase(St.find(out));
		out-=ll(n+1);
		St.insert(out);
		ap++;
	}
	printf("%lld\n",ap);
	return 0;
}