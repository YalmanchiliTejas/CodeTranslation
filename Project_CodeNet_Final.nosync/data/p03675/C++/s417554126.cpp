
/*\
 * ...
 * ......
 * In the name of ALLAH
 * ......
 * ...
 */

#include <bits/stdc++.h>

using namespace std;
#define Size(x) ((int)(x).size())
#define pb push_back
#define LD_OUT setprecision(12) << fixed
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int INF = 1e9 + 10 , MN =2e5 + 10;

int arr[MN];

int main()
{
	ios_base :: sync_with_stdio(false) ,cin.tie(0) , cout.tie(0);
	deque<int>deq;
	int n;cin>>n;
	for(int i=0;i<n;++i) cin >> arr[i];
	for(int i=0;i<n;++i)
		if(i&1) deq.push_front(arr[i]);
		else deq.push_back(arr[i]);
	if(n&1){
		for(int i=Size(deq)-1;~i;--i) cout << deq[i] << ' ';
	}else
		for(auto x:deq) cout << x << ' ';
	cout << '\n';
	return 0;
}
