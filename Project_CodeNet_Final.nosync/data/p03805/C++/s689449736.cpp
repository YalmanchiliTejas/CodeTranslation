#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
using namespace std;
int n,m;
vector<int> a[9];
long long num;
bool use[9];
bool ok()
{
	int i;
	for(i=0;i<n;i++) if(!use[i]) return 0;
	return 1;
}
void dfs(int lst,int dp)
{
//	cout<<lst<<endl;
	if(dp==n-1){
		if(ok()) num++;
		return;
	}else{
		int i;
		for(i=0;i<a[lst].size();i++){
			if(!use[a[lst][i]]){
				use[a[lst][i]]=1;
				dfs(a[lst][i],dp+1);
				use[a[lst][i]]=0;
			}
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int x,y,i,j;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}
	use[0]=1;
	dfs(0,0);
	cout<<num<<endl;
	return 0;
}
