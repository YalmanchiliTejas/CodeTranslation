#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define RREP(i,n) RFOR(i,0,n)

const int _N = 3e5 + 100;

int n;

/// --BIT--

struct BIT {
	int data[_N+1];
	void init(int n){
		REP(i, n+1){
			data[i] = 0;
		}
	}
	void add(int i, int x){
		i++;
		while(i<=n){
			data[i]+=x;
			i+=i&-i;
		}
	}
	// return sum of [0, i]
	// max is 3e5 -> int
	int sum(int i){
		i++;
		int s = 0;
		while(i>=1){
			s += data[i];
			i-=i&-i;
		}
		return s;
	}
};

/// --BIT--

BIT tree;
int d[_N];
int main(){
	cin >> n;
	REP(i, n){
		cin >> d[i];
		d[i] /= 10;
	}
	tree.init(n);
	tree.add(0, 1);
	tree.add(1, -1);
	REP(i, n-1){
		if(tree.sum(i) > 0){
			tree.add(i+1, 1);
			int t = i+1+d[i];
			if(t<n)tree.add(t, -1);
		}
	}

	if(tree.sum(n-1) == 0){
		cout << "no" << endl;
		return 0;
	}

	tree.init(n);
	tree.add(0, 1);
	tree.add(1, -1);
	REP(i, n-1){
		if(tree.sum(i) > 0){
			tree.add(i+1, 1);
			int t = i+1+d[n-1-i];
			if(t<n)tree.add(t, -1);
		}
	}

	if(tree.sum(n-1) == 0){
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
}