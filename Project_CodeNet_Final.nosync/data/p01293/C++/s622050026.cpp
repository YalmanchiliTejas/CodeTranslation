#include <iostream>
#include <string>
#include <vector>

using namespace std;

int evaluate(const string &trump, const string &led, const string &s){
	int score = 0;
	if(isdigit(s[0])){
		score = s[0] - '0';
	}else if(s[0] == 'T'){
		score = 10;
	}else if(s[0] == 'J'){
		score = 11;
	}else if(s[0] == 'Q'){
		score = 12;
	}else if(s[0] == 'K'){
		score = 13;
	}else if(s[0] == 'A'){
		score = 14;
	}
	if(s[1] == led[1]){ score += 15; }
	if(s[1] == trump[0]){ score += 30; }
	return score;
}

int main(){
	while(true){
		string trump;
		cin >> trump;
		if(trump == "#"){ break; }
		vector<string> cards[4];
		for(int i = 0; i < 4; ++i){
			cards[i].resize(13);
			for(int j = 0; j < 13; ++j){ cin >> cards[i][j]; }
		}
		int score[4] = { 0 };
		int dealer = 3;
		for(int i = 0; i < 13; ++i){
			const string p = cards[dealer][i];
			int winner = dealer, highest = 0;
			for(int j = 0; j < 4; ++j){
				const int s = evaluate(trump, p, cards[j][i]);
				if(s > highest){
					highest = s;
					winner = j;
				}
			}
			++score[winner];
			dealer = winner;
		}
		const int ns = score[0] + score[2], ew = score[1] + score[3];
		if(ns > ew){
			cout << "NS " << (ns - 6) << endl;
		}else{
			cout << "EW " << (ew - 6) << endl;
		}
	}
	return 0;
}