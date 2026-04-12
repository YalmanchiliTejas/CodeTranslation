#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<string>
#include <ios>     
#include <iomanip> 
using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

const llong MOD = 1000000007;

llong gcd(llong a, llong b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

llong lcm(llong a, llong b) {
	llong g = gcd(a, b);
	return a * b / g;
}

//ここまで共通


int N;
string S;
char SS[100010], SW[100010], WS[100010], WW[100010];
bool FSS, FSW, FWS, FWW;
int main() {
	//input
	cin >> N >> S;
	S.push_back(S[0]);
	S.push_back(S[1]);
	S.push_back(S[2]);

	//Sheep Sheep
	SS[0] = SS[1] = 'S';
	FSS = false;
	for (int i = 2; i < N + 2; i++) {
		if ((SS[i - 1] == 'S') == (S[i - 1] == 'x')) {
			if (SS[i - 2] == 'S') SS[i] = 'W';
			else SS[i] = 'S';
		}

		else {
			if (SS[i - 2] == 'S') SS[i] = 'S';
			else SS[i] = 'W';
		}
	}
	
	if (SS[N] == SS[0] && SS[N + 1] == SS[1]) FSS = true;

	

	

	//Sheep Wolf
	SW[0] = 'S';
	SW[1] = 'W';
	FSW = false;
	for (int i = 2; i < N + 2; i++) {
		if ((SW[i - 1] == 'S') == (S[i - 1] == 'x')) {
			if (SW[i - 2] == 'S') SW[i] = 'W';
			else SW[i] = 'S';
		}

		else {
			if (SW[i - 2] == 'S') SW[i] = 'S';
			else SW[i] = 'W';
		}
	}

	if (SW[N] == SW[0] && SW[N + 1] == SW[1]) FSW = true;





	//Wolf Sheep
	WS[0] = 'W';
	WS[1] = 'S';
	FWS = false;
	for (int i = 2; i < N + 2; i++) {
		if ((WS[i - 1] == 'S') == (S[i - 1] == 'x')) {
			if (WS[i - 2] == 'S') WS[i] = 'W';
			else WS[i] = 'S';
		}

		else {
			if (WS[i - 2] == 'S') WS[i] = 'S';
			else WS[i] = 'W';
		}
	}

	if (WS[N] == WS[0] && WS[N + 1] == WS[1]) FWS = true;



	//Wolf Wolf
	WW[0] = WW[1] = 'W';
	FWW = false;
	for (int i = 2; i < N + 2; i++) {
		if ((WW[i - 1] == 'S') == (S[i - 1] == 'x')) {
			if (WW[i - 2] == 'S') WW[i] = 'W';
			else WW[i] = 'S';
		}

		else {
			if (WW[i - 2] == 'S') WW[i] = 'S';
			else WW[i] = 'W';
		}
	}

	if (WW[N] == WW[0] && WW[N + 1] == WW[1]) FWW = true;

	//出力
	if (FSS) {
		for (int i = 0; i < N; i++) {
			cout << SS[i];
		}
	}
	else if (FSW) {
		for (int i = 0; i < N; i++) {
			cout << SW[i];
		}
	}
	else if (FWS) {
		for (int i = 0; i < N; i++) {
			cout << WS[i];
		}
	}
	else if (FWW) {
		for (int i = 0; i < N; i++) {
			cout << WW[i];
		}
	}
	else cout << -1;
	
	
	return 0;
}
