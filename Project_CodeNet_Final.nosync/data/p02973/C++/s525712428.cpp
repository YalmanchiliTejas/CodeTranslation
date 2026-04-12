/**
 * @Author:      G_bg
 * @DateTime:    2019-07-20 20:50:07
 * @Description: 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = 3.1415926535898;
const double E = 2.718281828459;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const int maxn=1e5+10;
int a[maxn];
multiset<int> s;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++){
		s.insert(a[i]);
		if(*s.begin() < a[i]){
			auto x = s.find(a[i]);
			s.erase(--x);
		}
	}
	cout << s.size() << endl;
	//system("pause");
	return 0;
}