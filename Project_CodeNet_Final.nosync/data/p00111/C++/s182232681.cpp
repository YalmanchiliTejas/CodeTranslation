#include<iostream>
#include<iomanip>
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

//#define int long long
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) {cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) {cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
const int MOD = 1e9 + 7;

signed main() {
	pair<char, string> A[32] = {
		make_pair(' ',"101"),
		make_pair('\'',"000000"),
		make_pair(',',"000011"),
		make_pair('-',"10010001"),
		make_pair('.',"010001"),
		make_pair('?',"000001"),
		make_pair('A',"100101"),
		make_pair('B',"10011010"),
		make_pair('C',"0101"),
		make_pair('D',"0001"),
		make_pair('E',"110"),
		make_pair('F',"01001"),
		make_pair('G',"10011011"),
		make_pair('H',"010000"),
		make_pair('I',"0111"),
		make_pair('J',"10011000"),
		make_pair('K',"0110"),
		make_pair('L',"00100"),
		make_pair('M',"10011001"),
		make_pair('N',"10011110"),
		make_pair('O',"00101"),
		make_pair('P',"111"),
		make_pair('Q',"10011111"),
		make_pair('R',"1000"),
		make_pair('S',"00110"),
		make_pair('T',"00111"),
		make_pair('U',"10011100"),
		make_pair('V',"10011101"),
		make_pair('W',"000010"),
		make_pair('X',"10010010"),
		make_pair('Y',"10010011"),
		make_pair('Z',"10010000")
	};
	pair<string, char> B[34] = {
		make_pair("00000",'A'),
		make_pair("00001",'B'),
		make_pair("00010",'C'),
		make_pair("00011",'D'),
		make_pair("00100",'E'),
		make_pair("00101",'F'),
		make_pair("00110",'G'),
		make_pair("00111",'H'),
		make_pair("01000",'I'),
		make_pair("01001",'J'),
		make_pair("01010",'K'),
		make_pair("01011",'L'),
		make_pair("01100",'M'),
		make_pair("01101",'N'),
		make_pair("01110",'O'),
		make_pair("01111",'P'),
		make_pair("10000",'Q'),
		make_pair("10001",'R'),
		make_pair("10010",'S'),
		make_pair("10011",'T'),
		make_pair("10100",'U'),
		make_pair("10101",'V'),
		make_pair("10110",'W'),
		make_pair("10111",'X'),
		make_pair("11000",'Y'),
		make_pair("11001",'Z'),
		make_pair("11010",' '),
		make_pair("11011",'.'),
		make_pair("11100",','),
		make_pair("11101",'-'),
		make_pair("11110",'\''),
		make_pair("11111",'?')
	};

	map<string, char> a;
	map<char, string> b;

	rep(i, 0, 32) {
		a[A[i].second] = A[i].first;
	}
	rep(i, 0, 34) {
		b[B[i].second] = B[i].first;
	}

	for (string s; getline(cin, s);) {
		string t = "";
		rep(i, 0, s.size())t += b[s[i]];
		//dump(t);
		string ans = "", prev = "";
		for (int l = 0;;) {
			rep(len, 1, t.size() - l + 1) {
				//dump(t.substr(l, len));
				if (a.count(t.substr(l, len))) {
					//dump(t.substr(l, len));
					ans += a[t.substr(l, len)];
					l += len;
					break;
				}
			}
			if (ans == prev)break;
			prev = ans;
			//dump(ans);
		}
		cout << ans << endl;
	}
	return 0;
}