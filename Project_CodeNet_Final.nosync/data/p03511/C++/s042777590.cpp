//置き換えて解を改善する系。
//s + tとt + sの順序を考えると、最適解はs…st…tまたはt…ts…sの形だと分かる。
//[s…s]と[t…t]の順序(文字数=lcm(|s|, |t|))を考えると、最適解は、[sをできるだけ多く]t…t, [sをできるだけ少なく]t…t, とその逆の
//4パターンの形のどれかになると分かる。4パターン試す時間はあるので、試してminを取ればよい。
//sとtの個数をそれぞれx, yとおくと、|s|x + |t|y = lとなればよいことが分かる。O(l)が間に合うので, xを全部試せばOK。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int l;
string s;
string t;

string getS(int type, int x, int y) {
	string ret;
	
	if (type == 0) {
		for (int i = 0; i < x; i++) ret += s;
		for (int i = 0; i < y; i++) ret += t;
	}
	else {
		for (int i = 0; i < y; i++) ret += t;
		for (int i = 0; i < x; i++) ret += s;
	}
	return ret;
}

int main() {
	cin >> l >> s >> t;
	int n = s.length();
	int m = t.length();
	
	int minX = 114514;
	int maxX = -114514;
	for (int x = 0; x * n <= l; x++) {
		if ((l - x * n) % m != 0) continue;
		if (minX > x) minX = x;
		if (maxX < x) maxX = x;
	}
	
	int y1 = (l - minX * n) / m;
	int y2 = (l - maxX * n) / m;
	
	string s1 = getS(0, minX, y1);
	string s2 = getS(0, maxX, y2);
	string s3 = getS(1, minX, y1);
	string s4 = getS(1, maxX, y2);
	
	string ans = min(s1, min(s2, min(s3, s4)));
	cout << ans << endl;
	return 0;
}