#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	multiset<int> st;
	for(int i=0; i<n; ++i){
		int x;
		cin >> x;
		auto it = st.upper_bound(-x);
		if(it==st.end()){
			st.insert(-x);
		}
		else{
			st.erase(it);
			st.insert(-x);
		}
	}
	cout << len(st) << endl;
}
