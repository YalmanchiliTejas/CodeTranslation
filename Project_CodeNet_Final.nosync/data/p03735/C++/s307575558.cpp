#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
using namespace std;

int N;
int M0 = 2e9, M1 = -1;
int A0,A1,B0,B1,id0,id1;

struct Node{
	int x,y;
	Node(int x=0, int y=0):x(x), y(y){}
	
	bool operator < (const Node& n1) const{
		return min(x,y) < min(n1.x,n1.y);
	}
} n[MAXN];

LL solve0(){
	if(id0==id1) return 1e18;
	A0 = M0;
	A1 = M1;
	
	static int py0[MAXN], py1[MAXN];
	py0[0] = 1e9;
	py1[0] = 0;
	int x,y,ans = 1e9;
	for(int i=1;i<N;i++){
		x = n[i].x; y = n[i].y;
		py0[i] = min(py0[i-1], y);
		py1[i] = max(py1[i-1], y);
		ans = min(ans, max(n[N].x, py1[i]) - min(n[i+1].x, py0[i]));
	}
	return (LL)ans*(A1-A0);
}

LL solve1(){
	A1 = M1;
	B0 = M0;
	
	if(n[id0].x == M0) A0 = n[id0].y;
	else A0 = n[id0].x;
	if(n[id1].x == M1) B1 = n[id1].y;
	else B1 = n[id1].x;

	int x,y;
	for(int i=1;i<=N;i++){
		if(i==id0 || i==id1) continue;
		x = n[i].x; y = n[i].y;
		
		B1 = max(B1, min(x, y));
		A0 = min(A0, max(x, y));
	}
	return (LL)(A1-A0)*(B1-B0);
}

void work(){
	scanf("%d", &N);
	
	int x,y;
	for(int i=1;i<=N;i++){
		scanf("%d%d", &x, &y);
		n[i].x = min(x, y);
		n[i].y = max(x, y);
	}
	sort(n+1, n+1+N);
	
	M0 = 2e9, M1 = -1;
	for(int i=1;i<=N;i++){
		x = n[i].x; y = n[i].y;
		if(M0 > min(x, y)){
			id0 = i;
			M0 = min(x, y);
		}
		if(M1 < max(x, y)){
			id1 = i;
			M1 = max(x, y);
		}
	}

	printf("%lld\n", min(solve0(), solve1()));
}

int main(){
	//freopen("01.in", "r", stdin);
	//freopen("01.ans", "w", stdout);
	int T;
	//scanf("%d", &T);
	T = 1; 
	while(T--){
		work();
	}
	
	return 0;
}
