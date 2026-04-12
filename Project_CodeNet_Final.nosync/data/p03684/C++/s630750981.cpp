#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int n, a[100005], val[100005],set[100005];
int findSet(int x) {
	if (set[x] == x)
		return x;
	return set[x] = findSet(set[x]);
}

void unionSet(int x, int y)
{
	int fx = findSet(x);
	int fy = findSet(y);
	if(fx!=fy)
		set[fx] = fy;
}
struct road {
	long long int len,turn1,turn2;
};
struct road rx[100005],ry[100005];
struct point {
	long long int x,y,turn;
};
struct point po[100005],po2[100005];
bool cmp(struct point p1, struct point p2)
{
	if(p1.x<p2.x)	return true;
	if(p1.x>=p2.x)	return false;
}
bool cmp2(struct point p1, struct point p2)
{
	if(p1.y<p2.y)	return true;
	if(p1.y>=p2.y)	return false;
}

bool cmprx(struct road r1, struct road r2)
{
	if(r1.len<r2.len)	return true;
	if(r1.len>=r2.len)	return false;
}
bool cmpry(struct road r1, struct road r2)
{
	if(r1.len<r2.len)	return true;
	if(r1.len>=r2.len)	return false;
}
int main()
{
	int i,j;
	scanf("%lld",&n);
	for(int i=0; i<=n; i++)	set[i] =i;
	for(i=0; i<n; i++)
    {
		scanf("%lld%lld",&po[i].x,&po[i].y);
		po2[i].x = po[i].x;
		po2[i].y = po[i].y;
		po[i].turn = i+1;
		po2[i].turn = i+1;
	}
	sort(po,po+n,cmp);
	sort(po2,po2+n,cmp2);
	for(i=1; i<n; i++)
    {
		rx[i-1].turn1 = po[i-1].turn;
		rx[i-1].turn2 = po[i].turn;
		rx[i-1].len = fabs(po[i-1].x - po[i].x);
	}
	for(i=1; i<n; i++)
    {
		ry[i-1].turn1 = po2[i-1].turn;
		ry[i-1].turn2 = po2[i].turn;
		ry[i-1].len = fabs(po2[i-1].y - po2[i].y);
	}
	sort(rx,rx+n-1,cmprx);
	sort(ry,ry+n-1,cmpry);
	long long int ans = 0;
	int fc1=0,fc2=0;
	int count = 0;
	for(; count<n-1; )
    {
		long long int r1 = rx[fc1].len, r2 = ry[fc2].len;
		if(r1<r2) {
			if(findSet(rx[fc1].turn1)!=findSet(rx[fc1].turn2))
            {
				ans+=rx[fc1].len;
				unionSet(rx[fc1].turn1,rx[fc1].turn2);
				count++;
			}
			fc1++;
		} else {
			if(findSet(ry[fc2].turn1)!=findSet(ry[fc2].turn2))
            {
				ans+=ry[fc2].len;
				unionSet(ry[fc2].turn1,ry[fc2].turn2);
				count++;
			}
			fc2++;
		}
	}
	printf("%lld",ans);
	return 0;
}
