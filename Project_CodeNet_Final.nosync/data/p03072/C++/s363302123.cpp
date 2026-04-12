#include<algorithm>
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
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int n,a[100],ans=1;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=1;i<n;i++){
		int f=0;
		for (int j=0;j<i;j++) if (a[j]>a[i]) f=1;
		if (f==0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}