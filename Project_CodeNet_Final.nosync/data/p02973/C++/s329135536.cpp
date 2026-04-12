#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define rep(i,n) for(int i=0;i<(n);i++)   

using namespace std;  

int main(void){
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N)cin >> a[i];
	deque<int> d;
	rep(i,N){
		int p = lower_bound(ALL(d),a[i]) - d.begin();
		if(p==0)d.push_front(a[i]);
		else d[p-1] = a[i];
	}
	cout << d.size() << endl;
}