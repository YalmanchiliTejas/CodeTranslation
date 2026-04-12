#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
	int N; cin >> N;
	deque<int> B(N);
	rep(i,N) cin >> B[i];
	sort(B.begin(),B.end());
	ll ans = 0;
	rep(i,2){
		deque<int> q;
		deque<int> A = B;
		int now;
		if(i == 0){
			q.push_back(A[0]);
			A.pop_front();
			now = 0;
		}
		else{
			q.push_back(A[N-1]);
			A.pop_back();
			now = 1;
		}
		while(!A.empty()){
			int M = A.size();
			if(now == 0){
				q.push_front(A[M-1]);
				if(M >= 2) q.push_back(A[M-2]);
				A.pop_back();
				if(M >= 2) A.pop_back();
			}
			if(now == 1){
				q.push_front(A[0]);
				if(M >= 2) q.push_back(A[1]);
				A.pop_front();
				if(M >= 2) A.pop_front();
			}
			now = 1-now;
		}
		ll nowans = 0;
		rep(i,N-1){
			nowans += abs(q[i]-q[i+1]);
		}
		ans = max(ans,nowans);
	}
	cout << ans << endl;	
}

