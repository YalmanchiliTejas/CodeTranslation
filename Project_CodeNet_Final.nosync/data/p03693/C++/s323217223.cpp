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
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int a,b,c,d;
	cin>>a>>b>>c;
	d=100*a+10*b+c;
	if(d%4) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
	#ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
}
