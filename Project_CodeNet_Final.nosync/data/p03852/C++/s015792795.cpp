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
	
	char c;
	cin >> c;
	if(c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u')puts("vowel");
	else puts("consonant");
	return 0;
}
