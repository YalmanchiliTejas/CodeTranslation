#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <deque>
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
#include <map>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <cwchar>
#include <cwctype>
#define mp make_pair
#define fs first
#define se second
#define memset(a,t) memset(a,t,sizeof(a))
#define all(v) v.begin(),v.end()
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define MN 0LL
#define MX 20000000000000005
using namespace std;
int a[200005];
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int n,i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=n-1;i>-1;i-=2) cout<<a[i]<<" ";
	for(i=n%2;i<n;i+=2) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
	#ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
}
