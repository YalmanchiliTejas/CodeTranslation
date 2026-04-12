#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	while(1){
		int n,l,r; cin >> n >> l >> r;
		if(n==0&&l==0&&r==0)break;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		auto uruu=[&](int x){
			for(int i=0;i<n;i++){
				if(x%a[i]==0)return (i+1)%2;
			}
			return (n+1)%2;
		};
		int res=0;
		for(int i=l;i<=r;i++){
			res+=uruu(i);
		}
		cout << res << endl;
	}
}


