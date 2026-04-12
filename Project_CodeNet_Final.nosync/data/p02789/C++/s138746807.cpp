/*我是菜鸡
╭╮＿＿╭╭╭╭╭＿＿╭╮
│　　　　　　　　　　　│　
│　　　　　　　　　　　│　
│　●　╭———╮　●　│　
│≡　　│●　●│　　≡│
│　　  ╰———╯　　　│
╰——┬○————┬—○╯
*/
#include<bits/stdc++.h>
#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define cci ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int ans[maxn][maxn];
int main() {
	cci;
	//ifstream cin("E:\\acm dream\\in.txt");
	//ofstream cout("E:\\acm dream\\out.txt");
	int n, m;
	while (cin >> n >> m) {
		if (n == m)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}