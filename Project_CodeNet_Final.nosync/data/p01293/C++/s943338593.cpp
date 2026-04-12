#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <numeric>
#include <ctime>
using namespace std;


//global var
string card[4][13];
char trump, T;
string ans_team;
int ans_score;
map<char, int> h;

//function
struct State{
	int n, id;
	char m;

	State(){};
	State(int n_, int id_, char m_){
		n = n_;
		id = id_;
		m = m_;
	};
};

bool operator < (const State &a, const State &b){
	if(a.m == trump){
		if(b.m == trump){
			return (a.n < b.n);
		}else{
			return false;
		}
	}else{
	
		if(b.m == trump){
			return true;
		}else{
	 		if(a.n == b.n){
	 			return (a.id > b.id);
	 		}
	 		
			return a.n < b.n;
	 	}
	 		
	}
}

//card state
State get_state(string c, int p, int start){
	int n = h[c[0]], id;
	char m = c[1];
	
	for(int i = 0, k = start; i < 4; i++, (k = (k + 1) % 4)){
		if(k == p){
			id = i;
			break;
		}
	}

	return State(n, id, m);
}

//solution func
void solve(){
	int start = 0;
	int NS = 0, EW = 0;
	
	for(int j = 0; j < 13; j++){
		int win;
		State win_s;
		
		bool flag = false;
		for(int i = 0; i < 4; i++){
			State s = get_state(card[i][j], i, start);
			
			if(s.m == T){
				flag = true;
				
				break;
			}
		}
		if(flag){
			trump = T;
		}else{
			State s = get_state(card[start][j], start, start);
			trump = s.m;
		}
		
		for(int i = 0; i < 4; i++){
			State s = get_state(card[i][j], i, start);
			
			if(i == 0){
				win = 0;
				win_s = s;
			}else if(win_s < s){
				win = i;
				win_s = s;
			}
		}
		/*
		// debug
		cout << j << " ";
		if(win == 0){
			cout << "N";
		}
		if(win == 1){
			cout << "E";
		}
		if(win == 2){
			cout << "S";
		}
		if(win == 3){
			cout << "W";
		}
		cout << " " << trump << endl;
		//
		*/
		
		if(win == 0 || win == 2){
			NS++;
		}
		else{
			EW++;
		}
		start = win;
	}
	
	if(EW < NS){
		ans_team = "NS";
		ans_score = NS - 6;
	}else{
		ans_team = "EW";
		ans_score = EW - 6;
	}
}

int main(){
	h['T'] = 10;
	h['J'] = 11;
	h['Q'] = 12;
	h['K'] = 13;
	h['A'] = 14;
	for(char c = '2'; c <= '9'; c++){
		h[c] = c - '0';
	}
	
	while(cin >> T){
		if(T == '#'){
			break;
		}
	
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 13; j++){
				cin >> card[i][j];
			}	
		}
		
		solve();
	
		cout << ans_team << " " << ans_score << endl;
	}
}