#include <iostream>
#include <stack>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int n, g;
int turn;

void solve(){
	stack<int> st;
	st.push(0);
	cin >> g;
	turn = g;
	for(int i = 1; i < n; i++){
		cin >> g;
		if(i%2 == 0){
			if(turn != g){
				st.push(i);
				turn = g;
			}
		} else{
			if(turn != g){
				if(st.size() != 1) st.pop();
				turn = g;
			}
		}
	}
	int ans = 0;
	int s, e = n;
	int si = st.size();
	for(int i = 0; i < si; i++){
		s = st.top();
		st.pop();
		if(turn == 0) ans += e-s;
		turn = (turn+1)%2;
		e = s;
	}
	cout << ans << endl;
}

int main(){
	while(cin >> n,n) solve();
}