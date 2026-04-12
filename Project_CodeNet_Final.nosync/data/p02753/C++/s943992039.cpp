#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
	string S;
	cin >> S;
	set<char> st;
	for(auto& c : S) st.insert(c);
	if(st.size() == 1) cout << "No" << endl;
	else cout << "Yes" << endl;
}
