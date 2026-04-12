
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int strength( char ch ) {
	if( ch > '0' && ch <= '9' ) return ch - '0';
	if( ch == 'T' ) return 10;
	if( ch == 'J' ) return 11;
	if( ch == 'Q' ) return 12;
	if( ch == 'K' ) return 13;
	if( ch == 'A' ) return 14;
}

int max( int p, int q ) {
	if( p > q ) return p;
	return q;
}

int main(void){

	string ans[] = { "NS", "EW" };

	while( true ) {
		
		int start = WEST;
		char trump;
		string cards[4][52/4];
		int tricks[2] = { 0 };

		cin >> trump;
		if( trump == '#' ) break;

		//カードの情報を取得する
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 52/4; j++) {
				cin >> cards[i][j];
			}
		}

		//シュミレート
		for( int i = 0; i < 13; i++) {
			int winner, rank;
			char suit;

			winner = start;
			rank = strength( cards[start][i][0] );
			suit = cards[start][i][1];

			for( int j = 1; j < 4; j++) {
				//スートが現在最強のものと同じ場合
				int tmp = ( start + j ) % 4;
				if( suit == cards[ tmp ][i][1] ){
					if( rank < strength( cards[ tmp ][i][0] ) ) {
						winner = tmp;
						rank = strength( cards[ tmp ][i][0] );
					}
				} else if( cards[ tmp ][i][1] == trump ) {
					//切り札が出る場合
					if( suit != trump ) {
						winner = tmp;
						suit = trump;
						rank = strength( cards[ tmp ][i][0] );
					} else {
						if( strength( cards[ tmp ][i][0] ) > rank  ) {
							winner = tmp;
							rank = strength( cards[ tmp ][i][0] );
						}
					}
				}
			}

			tricks[ winner % 2 ] ++;
			start = winner;

		}
		cout << ans[ tricks[EAST] > tricks[NORTH] ] << " " << max( tricks[EAST] , tricks[NORTH] ) - 6 << endl;

	}

	return 0;
}