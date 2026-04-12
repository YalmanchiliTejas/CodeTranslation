#include <bits/stdc++.h>
#define INF INT_MAX
#define endl '\n'
#define ll long long int
#define N 200006
using namespace std;

inline int redi() {
	int ret = 0,f = 0;char ch = getchar_unlocked();
	while (!isdigit (ch)) {
		if (ch == '-') f = 1;
		ch = getchar_unlocked();
	}
	while (isdigit (ch)) {
		ret = ret*10  + ch - 48;
		ch = getchar_unlocked();
	}
	return f?-ret:ret;
}
inline void print(int x) {
	if(x<0) {putchar_unlocked('-');x=-x;}
	int y=10,len=1;
	while(y<=x)    {y*=10;len++;}
	while(len--){y/=10;putchar_unlocked(x/y+48);x%=y;}
}

inline void init()
{
	int n,num[N];
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> num[i];
	
	int q[N],p=1;
	q[0]=num[n-1];

	for(int i=n-2;i>=0;--i){
		if(num[i]>=q[p-1])
			q[p++]=num[i];
		else
			q[upper_bound(q,q+p,num[i])-q]=num[i];
	}
	cout << p << endl;
}

inline void solve()
{
}

int main()
{
	//freopen("input.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	init();
	solve();
	cout << flush;

	return 0;
}
