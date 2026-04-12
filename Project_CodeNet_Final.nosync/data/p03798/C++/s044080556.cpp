#include"bits/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define print(x) cout<<x<<endl;
typedef long long ll;

int n;
string s;
int int_s;
int ans[100005];
string ans_s[100005];
int flag = 0;

bool is(int s1, int s2) {
	ans[0] = s1;	//ans[i]=-1のとき羊、1の時狼
	ans[1] = s2;
	rep(i, 1, n) {
		if (ans[i] == -1 && s[i] == 'o') { ans[i + 1] = ans[i - 1]; }
		else if (ans[i] == -1 && s[i] == 'x') { ans[i + 1] = -ans[i-1]; }
		else if (ans[i] == 1 && s[i] == 'o') { ans[i + 1] = -ans[i - 1]; }
		else if (ans[i] == 1 && s[i] == 'x') { ans[i + 1] = ans[i - 1]; }
	}
	//rep(i, 0, n )cout << ans[i];
	//cout << endl;
	int flag = 0;
	if (ans[n - 1] == -1 && s[n - 1] == 'o'&&ans[n - 2] == ans[0] \
		|| ans[n - 1] == -1 && s[n - 1] == 'x'&&ans[n - 2] != ans[0] \
		|| ans[n - 1] == 1 && s[n - 1] == 'o'&&ans[n - 2] != ans[0]\
		|| ans[n - 1] == 1 && s[n - 1] == 'x'&&ans[n - 2] == ans[0]) flag += 1;
	if (ans[0] == -1 && s[0] == 'o'&&ans[n - 1] == ans[1] \
		|| ans[0] == -1 && s[0] == 'x'&&ans[n - 1] != ans[1] \
		|| ans[0] == 1 && s[0] == 'o'&&ans[n - 1] != ans[1] \
		|| ans[0] == 1 && s[0] == 'x'&&ans[n - 1] == ans[1]) flag += 1;
	if (flag == 2)return 1;
	return 0;
}

int main() {

	cin >> n;
	cin >> s;
	int sw[8] = { -1,-1,-1,1,1,-1,1,1};
	for(int i=0;i<8;i+=2) {
		//print(j);
		if (is(sw[i], sw[i+1])) {
			rep(j, 0, n) {
				if (ans[j] == -1) { ans_s[j] = 'S'; }
				else if (ans[j] == 1) { ans_s[j] = 'W'; }
			}
			rep(j, 0, n) { cout<<ans_s[j];}
			cout << endl;
			return 0;
		}
	}
	
	print(-1); return 0;
}