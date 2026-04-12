#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
using namespace std;

int N;
int M0 = 2e9, M1 = -1;
int A0,A1,B0,B1,id0,id1;
int t0,t1;

struct Node{
	int x,y;
	Node(int x=0, int y=0):x(x), y(y){}
	
	bool operator < (const Node& n1) const{
		return x < n1.x;
	}
} n[MAXN];

LL solve0(){
	if(id0==id1) return 1e18;
	A0 = M0;
	A1 = M1;
	
	int py0[MAXN], py1[MAXN], fy0[MAXN], fy1[MAXN];
	py0[0] = fy0[N+1] = 1e9;
	py1[0] = fy1[N+1] = 0;
	int x,y;
	for(int i=1;i<=N;i++){
		x = n[i].x; y = n[i].y;
		py0[i] = min(py0[i-1], y);
		py1[i] = max(py1[i-1], y);
	}
	for(int i=N;i>=1;i--){
		x = n[i].x; y = n[i].y;
		fy0[i] = min(fy0[i+1], y);
		fy1[i] = max(fy1[i+1], y);
	}
	
	int ans = 1e9;
	for(int i=1;i<N;i++){
		ans = min(ans, max(n[N].x, py1[i]) - min(n[i+1].x, py0[i]));
	}	
	
	return (LL)ans*(A1-A0);
}

LL solve1(){
	A1 = M1;
	B0 = M0;
	A0 = t0;
	B1 = t1;

	int x,y;
	for(int i=1;i<=N;i++){
		if(i==id0 || i==id1) continue;
		x = n[i].x; y = n[i].y;
		
		B1 = max(B1, min(x, y));
		A0 = min(A0, max(x, y));
	}
	return (LL)(A1-A0)*(B1-B0);
}

int main(){
	ios::sync_with_stdio(0);
	
	cin>>N;
	
	int x,y;
	for(int i=1;i<=N;i++){
		cin>>x>>y;
		n[i].x = min(x, y);
		n[i].y = max(x, y);
	}
	sort(n+1, n+1+N);
	
	
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
	
	if(n[id0].x == M0) t0 = n[id0].y;
	else t0 = n[id0].x;
	if(n[id1].x == M1) t1 = n[id1].y;
	else t1 = n[id1].x;
	//cout<<t0<<" "<<t1<<endl;
	cout<<min(solve0(), solve1())<<endl;
	return 0;
}

/*
2
1 2
3 4
*/