#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

const char t[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
const char r[]=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string o[]={
	"101",
	"000000",
	"000011",
	"10010001",
	"010001",
	"000001",
	"100101",
	"10011010",
	"0101",
	"0001",
	"110",
	"01001",
	"10011011",
	"010000",
	"0111",
	"10011000",
	"0110",
	"00100",
	"10011001",
	"10011110",
	"00101",
	"111",
	"10011111",
	"1000",
	"00110",
	"00111",
	"10011100",
	"10011101",
	"000010",
	"10010010",
	"10010011",
	"10010000"
};

map<string,char> mp;

string get_dec_char(char c){
	int a = strchr(t,c) - t;
	string ret(5,'0');
	for (int i = 0; i < 5; i++){
		if(a & (1 << i)) ret[4-i]++;
	}
	return ret;
}

string decode(string s){
	string ret;
	for(int i =0 ; i < (int)s.size(); i++) ret.append(get_dec_char(s[i]));
	return ret;
}

string encode(string s){
	string ret;
	int cur = 0;
	for (int i = 0; i <= (int)s.size(); i++){
		string sub = s.substr(cur,i-cur);
		if(mp.find(sub) != mp.end()){
			cur = i;
			ret.push_back(mp[sub]);
		}
	}
	return ret;
}

string solve(string s){
	s = decode(s);
	return encode(s);
}

int main(){

	for (int i = 0; i < 32; i++){
		mp[o[i]] = r[i];
	}

	string s;
	while(getline(cin,s)){
		cout << solve(s) << endl;
	}

	return 0;
}