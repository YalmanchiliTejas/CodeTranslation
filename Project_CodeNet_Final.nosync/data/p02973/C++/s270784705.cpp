#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define print(x) cerr << (#x) << "is "<< x << "\n"
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;

ll arr[N],n;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	f(i,0,n){
		cin >> arr[i];
	}
	multiset<int> s;
	f(i,0,n){
		auto k = s.lower_bound(arr[i]);
		if(k==s.begin()){
			s.insert(arr[i]);
		}else{
			k--;
			s.erase(k);
			s.insert(arr[i]);
		}
	}
	cout << (int)s.size() << '\n';
	return 0;
}