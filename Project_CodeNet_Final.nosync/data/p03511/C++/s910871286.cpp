#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int main()
{
	int n=gi();
	string a,b;cin>>a>>b;
	if (a+b>b+a) swap(a,b);
	int A=a.size(),B=b.size(),lcm=A*B/__gcd(A,B);
	//for (int i=n/lcm*(lcm/A);i;i--) cout<<a;n%=lcm;
	//while (n%B) cout<<a,n-=A;
	//for (n/=B;n--;) cout<<b;
	string out;
	while (n%A) out+=b,n-=B;
	for (n/=A;n--;) cout<<a;
	cout<<out;
	return 0;
}
