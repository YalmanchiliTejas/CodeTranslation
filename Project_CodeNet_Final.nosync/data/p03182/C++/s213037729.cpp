#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N,M; vector<pair<int, int> > intv[200200];

const int Z = 1 << 18;

struct node{
	node(){sum = mx = 0;}
	node(long long x){
		sum = mx = x;
		if (mx < 0) mx = 0;
	}
	long long sum, mx;
	
	node operator +(node t){
		node r(0);
		r.sum = sum + t.sum;
		r.mx = mx;
		if (r.mx < sum + t.mx)
			r.mx = sum + t.mx;
		return r;
	}
}IT[Z*2];

node out(int x, int y)
{
	x += Z; y += Z;

	node l, r;
	while (x < y){
		if (x & 1) l = l + IT[x++];
		if (~y & 1) r = IT[y--] + r;
		x /= 2; y /= 2;
	} if (x == y) l = l + IT[x];
	return l + r;
}

void in(int x, long long p)
{
	x += Z;
	p += IT[x].sum;
	IT[x] = node(p);
	x /= 2;
	while (x){
		IT[x] = IT[x*2] + IT[x*2+1];
		x /= 2;
	}
}

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int l,r,a;
		scanf ("%d %d %d",&l,&r,&a);
		intv[r].push_back({l,a});
	}

	for (int i=1;i<=N;i++){
		auto r = out(0,i-1);
		in(i,r.mx);
		in(i+1,-r.mx);
		for (auto &p : intv[i]){
			in(p.first, p.second);
			in(i+1, -p.second);
		}
	}

	printf ("%lld\n",out(0,N).mx);

	return 0;
}
