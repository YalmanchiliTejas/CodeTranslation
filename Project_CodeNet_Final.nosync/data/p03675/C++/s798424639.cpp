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
using namespace std;
#define mp make_pair
#define sc second
#define fs first
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long LL;
typedef pair < int , int > pii;
int n,m,k,d,t,a[200005],b[600005];
int main(){
	int xb,x2;
	scanf("%d",&n);
	for(xb=0;xb<n;xb++){
		scanf("%d",&a[xb]);
	}
	int l=300000;
	int r=299999;
	bool cur=1;
	for(xb=0;xb<n;xb++){
		
		if(cur){
			b[++r]=a[xb];
		}
		else b[--l]=a[xb];
		cur=!cur;
	}
	if(cur){
		for(xb=l;xb<=r;xb++){
			printf("%d ",b[xb]);
		}
	}
	else{
		for(xb=r;xb>=l;xb--){
			printf("%d ",b[xb]);
		}
	}
	return 0;
}