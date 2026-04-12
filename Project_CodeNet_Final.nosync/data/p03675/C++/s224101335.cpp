#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priotity_queue
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ld PI=abs(acos(-1));
int n,a;
deque<int> que;

int main(){
	cin >> n;
	REP(i,0,n){
		cin >> a;
		if(i%2) que.push_front(a);
		else que.push_back(a);
	}
	
	if(n%2) RREP(i,n-1,0) cout << que[i] << " ";
	else REP(i,0,n) cout << que[i] << " ";
	cout << endl;
	return 0;
}
