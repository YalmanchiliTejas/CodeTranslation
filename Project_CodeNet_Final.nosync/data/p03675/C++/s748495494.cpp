#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<ctype.h>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<math.h>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<stdio.h>
#include<stdlib.h>
#include<streambuf>
#include<string.h>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
using namespace std;
int a[200010];
int main(void){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	deque<int> res;
	for (int i=1;i<=n;i++){
		if (i&1){
			res.push_back(a[i]);
		}
		else{
			res.push_front(a[i]);
		}
	}
	deque<int>::iterator it;
	if (n&1){
		it=res.end();
		it--;
		for (;it!=res.begin();it--){
			printf("%d ",*it);
		}
		printf("%d",*it);
	}
	else{
		it=res.begin();
		for (;it!=res.end();it++){
			printf("%d ",*it);
		}
	}
	return 0;
}