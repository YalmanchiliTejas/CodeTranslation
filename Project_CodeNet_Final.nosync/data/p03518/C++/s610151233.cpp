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

const int N=210;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int n,p[N];VI ans;
inline void move(int k) {
	ans.pb(k);
	for (int i=k;i<n;i++)
		swap(p[i],p[i-k]);
}
int main()
{
	n=gi();
	for (int i=0;i<n;i++) p[i]=gi();
	while (!is_sorted(p,p+n))
		if (p[0]&&p[0]<p[n-1])
			move(n-1);
		else
			move(1);
	cout<<ans.size()<<endl;
	for (int t:ans)
		cout<<t<<endl;
	return 0;
}
