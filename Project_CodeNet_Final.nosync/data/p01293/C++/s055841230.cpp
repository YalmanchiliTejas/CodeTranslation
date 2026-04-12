#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getScore(int num, char suit, char H, char R){
	int res = 0;
	if(suit == H) res += 100;
	else if(suit == R) res += 50;
	return res + num;
} 

int main(){
	char c;
	while(cin >> c){
		if(c=='#') break;
		int num[4][13];
		char suit[4][13];
		int read = 0;
		string buf;
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				cin >> buf;
				suit[i][j] = buf[1];
				if(isdigit(buf[0])) num[i][j] = (buf[0]-'0');
				if(buf[0]=='T') num[i][j] = 10;
				if(buf[0]=='J') num[i][j] = 11;
				if(buf[0]=='Q') num[i][j] = 12;
				if(buf[0]=='K') num[i][j] = 13;
				if(buf[0]=='A') num[i][j] = 14;
			}
		}
		int score = 0;
		for(int i=0;i<13;i++){
			int pos = read;
			char st = suit[read][i];
			int maxScore = getScore(num[read][i], suit[read][i], c, st);
			for(int j=read+1;j<read+4;j++){
				int score = getScore(num[j%4][i], suit[j%4][i], c, st);
				if(maxScore < score){
					pos = j%4;
					maxScore = score;
				}
			}
			read = pos;
			if(read%2==0) score++;
		}
		if(score > 6) cout << "NS " << score-6 << endl;
		else          cout << "EW " << 13-score-6 << endl;
	}
}