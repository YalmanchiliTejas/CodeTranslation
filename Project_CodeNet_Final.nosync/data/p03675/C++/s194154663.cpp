#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 2e5+10;
const lint LNF = 2e18;


int n, A[MAX];
deque<int> B;
bool fliped;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>A[i];
	for(int i=1; i<=n; i++){
		if(fliped){
			B.push_front(A[i]);
		} else {
			B.push_back(A[i]);
		}
		fliped^=true;
	}
	if(fliped) reverse(B.begin(), B.end());
	for(int x:B) cout<<x<<' ';
	cout<<'\n';

	return 0;
}
