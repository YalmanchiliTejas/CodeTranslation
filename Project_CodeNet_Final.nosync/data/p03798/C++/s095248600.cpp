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

class Program{

	int N;
	string answer;
	char ret[MAX_N];

	char nextchr(char center, char ans, char left){

		if ((center == 'S' && ans == 'o') || (center == 'W' && ans == 'x')){
			return left;
		}
		else{
			return (left == 'S' ? 'W' : 'S');
		}
	}

	bool check(char center, char ans, char left, char right){
		return right == nextchr(center, ans, left);
	}

	bool run(char first, char second){

		ret[0] = first;
		ret[1] = second;
		for (int i = 2; i < N; i++){
			ret[i] = nextchr(ret[i - 1], answer[i - 1], ret[i - 2]);
		}

		return (check(ret[0], answer[0], ret[N - 1], ret[1]) &&
			check(ret[N - 1], answer[N - 1], ret[0], ret[N - 2]));
	}

public :
	
	void main() {

		cin >> N;
		cin >> answer;

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
			rep(i, N){
				cout << ret[i];
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}

	}

};

int main() {
	Program p;
	p.main();
}