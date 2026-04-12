#include <bits/stdc++.h>
using namespace std;
#define int long long


template <class X> class Solve{
public:
	string s;
	int p;
	Solve(string s_){
		s = s_;
		s += "~";
		p = 0;
	}
	X one(){
		X r = num();
		while( s[p] == '+' || s[p] == '*' ){
			char c = s[p];
			p++;
			X l = num();
			if( c == '*' ){
				r *= l;
			}else{
				r += l;
			}
		}
		return r;
	}
	X num(){
		X ans = 0;
		while( s[p] >= '0' && s[p] <= '9'){
			ans = ans * 10 + s[p] - '0';
			p++;
		}
		return ans;
	}

	X two(){
		X r = three();
		while( s[p] == '+' ){
			char c = s[p];
			p++;
			X l = three();
			r += l;
		}
		return r;
	}

	X three(){
		X r = num();
		while( s[p] == '*' ){
			char c = s[p];
			p++;
			X l = num();
			r *= l;
		}
		return r;
	}
};

signed main(){
	string s;
	int n;
	cin >> s >> n;
	int b = 0;
	if( fabs(Solve<double>(s).one()-n) < 1e5 ){
		if( Solve<int>(s).one()-n == 0 ){
			b += 1;
		}
	}
	if( fabs(Solve<double>(s).two()-n) < 1e5 ){
		if( Solve<int>(s).two()-n == 0 ){
			b += 2;
		}
	}
	string table = "ILMU";
	cout << table[b] << endl;
	
}