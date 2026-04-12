#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <queue>
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
#define MN 0LL
#define Mx 200000005
#define Mn -Mx
#define MX 20000000000000005
using namespace std;
int readint(){
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	bool flag=(c=='-');
	if(flag)c=getchar();
	int x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return flag?-x:x;
}
inline string tos(int x){
	string s;
	while(x) s=(char)(x%10+'0')+s,x/=10;
	return s;
}
inline int toi(string s){
	int rt=0;
	for(int i=0;i<s.size();i++) rt=rt*10+(int)(s[i]-'0');
	return rt;
}
int main(){
	int i,j;
	long long n,m;
	long long ans=0;
	cin>>n>>m;
	if(m==0){
		cout<<(long long)((long long)(n)*(long long)(n))<<endl;
		return 0;
	}
	for(i=m+1;i<=n;i++){
		ans+=(long long)(((long long)(n/i)*(long long)(i-m)));
	}
	for(i=m;i<=n;i++){
		long long t=n%i;
		t=max(t-m+1,0LL);
		ans+=t;
	}
	cout<<ans<<endl;
	return 0;
}

