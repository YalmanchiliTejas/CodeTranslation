#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,a[555555],b[555555];
map<int,int> M;
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]),b[i]=a[i];
	sort(a+1,a+n+1);
	FOR(i,1,n){
		if (i-1>=(n-1)/2+1) M[a[i]]=a[(n-1)/2+1];
		else M[a[i]]=a[n-((n-1)/2+1)+1];
	}
	FOR(i,1,n) printf("%d\n",M[b[i]]);
	return 0;
}