#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// card[i][j] := プレイヤー i が j 回目に出したカード.
string card[4][13];
// Trump := 基準となる強いマーク, trump := この回で強いマーク.
char Trump, trump;
// h[c] := 文字 c に対応する数字.
char h[256] = {0};
// 解
string ans_team;
int ans_score;

// n := カードの数字, id := 順番, m := マーク.
struct State{
	int n, id;
	char m;
	State(){};
	State(int n_, int id_, char m_){
		n = n_; id = id_; m = m_;
	};
};
// カードの順序を定義.
bool operator<(const State &a, const State &b){
	if( a.m == trump ){
		return ( b.m == trump )? a.n < b.n : false;
	}else{
		if( b.m == trump ){
			return true;
		}else{
			return ( a.n == b.n )? a.id > b.id : a.n < b.n;
		}
	}
}

State get_state(string s, int p, int start){
	int n = h[s[0]], id;
	char m = s[1];
	
	for(int i = 0, k = start ; i < 4 ; i++, k = (k+1) % 4 ){
		if( k == p ){
			id = i;
			break;
		}
	}
	return State(n, id, m);
}

void solve(){
	int prev_win = 0, NS = 0, EW = 0;
	
	for(int j = 0 ; j < 13 ; j++ ){
		int win;
		State win_s;
		
		// マーク Trump を出したプレイヤーがいるかどうか. 
		bool flag = false;
		for(int i = 0 ; i < 4 ; i++ ){
			State s = get_state(card[i][j], i, prev_win);
			
			if( s.m == Trump ){
				flag = true;
				break;
			}
		}
		if( flag ){
			trump = Trump;
		}else{
			State s = get_state(card[prev_win][j], prev_win, prev_win);
			trump = s.m;
		}
		
		// どのプレイヤーが勝ったかチェック.
		for(int i = 0 ; i < 4 ; i++ ){
			State s = get_state(card[i][j], i, prev_win);
			
			if( i == 0 ){
				win = 0;
				win_s = s;
			}else if( win_s < s ){
				win = i;
				win_s = s;
			}
		}
		// 勝ったプレイヤーのチームに勝ち点追加.
		(win == 0 || win == 2)? NS++ : EW++;
		prev_win = win;
	}
	if( EW < NS ){
		ans_team = "NS";
		ans_score = NS - 6;
	}else{
		ans_team = "EW";
		ans_score = EW - 6;
	}
}

int main(){
	h['T'] = 10; h['J'] = 11; h['Q'] = 12; h['K'] = 13; h['A'] = 14;
	for(char c = '2' ; c <= '9' ; c++ ){
		h[c] = c - '0';
	}
	
	while( cin >> Trump, Trump != '#' ){
		for(int i = 0 ; i < 4 ; i++ ){
			for(int j = 0 ; j < 13 ; j++ ){
				cin >> card[i][j];
			}
		}
		solve();
		cout << ans_team << " " << ans_score << endl;
	}
}