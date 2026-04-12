#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	deque<int> deq;
	rep(i, n){
		int in;
		cin >> in;
		auto itr = lower_bound(deq.begin(), deq.end(), in);
		if(deq.size() == 0 || itr == deq.begin()){
			deq.push_front(in);
		}else{
			itr--;
			*itr = in;
		}
	}
	cout << deq.size() << endl;
	return 0;
}