#include <bits/stdc++.h>

using namespace std;

int toi(char a){
	if(a <= '9' && a >= '0'){
		return (int)(a - '0');
	}
	else{
		switch(a){
			case 'T': return 10;
			case 'J': return 11;
			case 'Q': return 12;
			case 'K': return 13;
			case 'A': return 14;
		}
	}
}

int con_suit(char a){
	switch(a){
		case 'S': return 0;
		case 'H': return 1;
		case 'D': return 2;
		case 'C': return 3;
	}
}

int main(){
	while(true){
		char c; cin >> c;
		if(c == '#')break;
		int best = con_suit(c);
		vector< vector<pair<int, int> > >  card(4, vector<pair<int ,int> >(13));
		vector<int> team(2,0);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 13; j++){
				string str;
				cin >> str;
				card[i][j] = make_pair(toi(str[0]), con_suit(str[1]));
			}
		}
		
		int win = -1;
		int score = 0;
		int suit = card[0][0].second;
		for(int turn = 0; turn < 13; turn++){
			win = -1;
			score = 0;
			for(int mem = 0; mem < 4; mem++){
				int c = card[mem][turn].first;
				//cerr << card[mem][turn].second << " " << suit << " * ";
				if( card[mem][turn].second == best && c > score){
					score = c;
					win = mem;
					//cerr << win << " ";
				}
			}

			//cerr << "done" << endl;
			if(win == -1){
				for(int i = 0; i < 4; i++){
					if( card[i][turn].second == suit && card[i][turn].first > score){
						score = card[i][turn].first;
						win = i;
					}
				}
			}
			if(win == -1){
				for(int i = 0; i < 4; i++){
					if( card[i][turn].first > score){
						score = card[i][turn].first;
						win = i;
					}
				}
			}
			//cout << win << " ";
			if( win % 2 == 0){
				team[0]++;
			}
			else{
				team[1]++;
			}
			suit = card[win][turn < 13 ? turn+1: 0].second;
		}
		if(team[0] > team[1]){
			cout << "NS" << " " << team[0]-6 << endl;
		}
		else{
			cout << "EW" << " " << team[1]-6 << endl;
		}
	}

	return 0;
}