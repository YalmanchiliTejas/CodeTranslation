// 失敗するからこそ そこから立ち向かって行く強さがあってそんな強さが本当の強さだと私は思うから
// ぜったいあきらめない
#if defined(DAIJOBU)
#include "/home/ichigo/includes.hpp"
#include "/home/ichigo/debug.hpp"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#include <bits/stdc++.h>
#define deb(x...)
#endif
#define FIO {ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);}

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
	FIO
	
	int a, b, c;
	cin >> a >> b >> c;
	if((b * 10 + c) % 4)puts("NO");
	else puts("YES");
	return 0;
}
