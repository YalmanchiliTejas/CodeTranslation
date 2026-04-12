#include <stdlib.h>
#include <iostream>
#include <climits>
#include <map>
using namespace std;

#define REP(i,n) for(long i=0; i<(long)(n); ++i)
#define FOR(i,k,n) for(long i=(k);i<(long)(n);++i)

bool does_exist(long n, bool* in, bool first, bool second);
bool answer(long n, bool* in, bool first, bool second);
void out_sw(bool in);

int main(){
	long n;
	cin >> n;
	bool *in = (bool *)calloc(n, sizeof(bool));
	char s;
	REP(i, n){
		cin >> s;
		if(s == 'o'){
			in[i] = true;
		}else{
			in[i] = false;
		}
	}
	if(does_exist(n, in, true, true)){
		answer(n, in, true, true);
		return 0;
	}
	if(does_exist(n, in, true, false)){
		answer(n, in, true, false);
		return 0;
	}
	if(does_exist(n, in, false, true)){
		answer(n, in, false, true);
		return 0;
	}
	if(does_exist(n, in, false, false)){
		answer(n, in, false, false);
		return 0;
	}
	cout << -1 << endl;
	return 0;
}

bool does_exist(long n, bool* in, bool first, bool second){
	bool *res = (bool *)calloc(n, sizeof(bool));
	res[0] = first;
	res[1] = second;
	FOR(i, 1, n-1){
		if(res[i]==in[i]){
			res[i+1] = res[i-1];
		}else{
			res[i+1] = !res[i-1];
		}
	}
	return ((in[n-1]==res[n-1])==(res[0] == res[n-2])) && 
			((in[0]==res[0])==(res[1] == res[n-1]));

}
bool answer(long n, bool* in, bool first, bool second){
	bool *res = (bool *)calloc(n, sizeof(bool));
	res[0] = first;
	res[1] = second;
	out_sw(res[0]);
	out_sw(res[1]);
	FOR(i, 1, n-1){
		if(res[i]==in[i]){
			res[i+1] = res[i-1];
		}else{
			res[i+1] = !res[i-1];
		}
		out_sw(res[i+1]);
	}
	cout << endl;
	return true;
}
void out_sw(bool in){
	if(in){
		cout << 'S';
	}else{
		cout << 'W';
	}

}