#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

int N;
string ans;
char ret[MAX_N];

char nextchr(char center, char left, char a){
	if (center == 'S' && a == 'o' && left == 'S'){ return 'S'; }
	if (center == 'S' && a == 'o' && left == 'W'){ return 'W'; }
	if (center == 'S' && a == 'x' && left == 'S'){ return 'W'; }
	if (center == 'S' && a == 'x' && left == 'W'){ return 'S'; }
	if (center == 'W' && a == 'o' && left == 'S'){ return 'W'; }
	if (center == 'W' && a == 'o' && left == 'W'){ return 'S'; }
	if (center == 'W' && a == 'x' && left == 'S'){ return 'S'; }
	if (center == 'W' && a == 'x' && left == 'W'){ return 'W'; }
}

bool check(char center, char left, char right, char a){

	if ((center == 'S' && a == 'o') || (center == 'W' && a == 'x')){
		return left == right;
	}
	else{
		return left != right;
	}

}

void print(){
	rep(i, N){
		cout << ret[i];
	}
	cout << endl;
}

bool run(char first, char second){

	ret[0] = first;
	ret[1] = second;
	for (int i = 2; i < N; i++){
		ret[i] = nextchr(ret[i - 1], ret[i - 2], ans[i - 1]);
	}

	return (check(ret[0], ret[N - 1], ret[1], ans[0]) && 
		    check(ret[N - 1], ret[0], ret[N - 2], ans[N - 1]));
}

int main() {

	cin >> N;
	cin >> ans;

	bool success = false;

	if (!success){
		success = run('S', 'S');
	}
	if (!success){
		success = run('S', 'W');
	}
	if (!success){
		success = run('W', 'S');
	}
	if (!success){
		success = run('W', 'W');
	}

	if (success){
		print();
	}
	else{
		cout << -1 << endl;
	}
	
}