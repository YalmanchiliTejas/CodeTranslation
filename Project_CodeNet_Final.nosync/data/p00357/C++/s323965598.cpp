#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
 
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	int maxi = 0;
	rep(i, n) cin >> d[i];
	rep(i, n){
		if(maxi < i) continue;
		maxi = max(maxi, i + d[i]/10);
	}
	
	if(maxi < n-1){
		cout << "no" << endl;
		return 0;
	}
	int mini = n-1;
	for(int i = n-1; i >= 0; --i){
		if(i < mini) continue;
		mini = min(mini, i - d[i]/10);
	}
	cout << (mini <= 0?"yes":"no") << endl;
}