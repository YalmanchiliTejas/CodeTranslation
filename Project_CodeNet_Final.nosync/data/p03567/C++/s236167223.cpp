/*
Author: CNYALI_LK
LANG: C++
PROG: Cf2017C_A.cpp
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef long long ll;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
char s[100];
int main(){
#ifdef cnyali_lk
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%s",s);
	for(int i=0;i+1<strlen(s);++i)if(s[i]=='A'&&s[i+1]=='C'){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}

