#include <iostream>
using namespace std;

int rank[128];
char trump;
string card[4][13];

int main(void){
	for(int i=2;i<10;i++) rank['0'+i] = i;
	rank['T'] = 10;
	rank['J'] = 11;
	rank['Q'] = 12;
	rank['K'] = 13;
	rank['A'] = 14;

	while(cin>>trump,trump!='#'){
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				cin>>card[i][j];
			}
		}

		int first = 0;
		int win[] = {0,0};

		for(int i=0;i<13;i++){
			int winner = 0, max = 0;
			bool flg = false; //trumpツつェツ出ツつスツつゥツづ個フツδ可グ
			char led = card[first][i][1];

			for(int j=0;j<4;j++){
				int r = rank[card[j][i][0]];
				char s = card[j][i][1];

				if(flg){
					if(s == trump && r > max){
						max = r;
						winner = j;
					}
				}
				else{
					if(s == trump){
						flg = true;
						max = r;
						winner = j;
					}
					else if(s == led && r > max){
						max = r;
						winner = j;
					}
				}
			}

			first = winner;
			win[winner%2]++;
		}

		if(win[0] > win[1])
			cout<<"NS "<<win[0]-6<<endl;
		else
			cout<<"EW "<<win[1]-6<<endl;
	}

	return 0;
}