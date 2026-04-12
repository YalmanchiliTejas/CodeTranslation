#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void start()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen("in.txt", "r", stdin);
    //   freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
int32_t main()
{
	//start();
    int n; cin >> n;
    if(n >= 30)cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
