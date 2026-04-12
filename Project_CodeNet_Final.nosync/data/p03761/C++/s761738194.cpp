#include<iostream>
using namespace std;

int main(){
	int n;
	char str[50][51];
	char alpha[50][26];

	for(int i = 0; i < 50; ++i){
		for(int j = 0; j <= 50; ++j){
			str[i][j] = 0;
		}

		for(int j = 0; j < 26; ++j){
			alpha[i][j] = 0;
		}
	}

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> str[i];
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= 50; ++j){
			if(str[i][j] == 0){
				break;
			}else if(str[i][j] == 'a'){
				alpha[i][0] += 1;
			}else if(str[i][j] == 'b'){
				alpha[i][1] += 1;
			}else if(str[i][j] == 'c'){
				alpha[i][2] += 1;
			}else if(str[i][j] == 'd'){
				alpha[i][3] += 1;
			}else if(str[i][j] == 'e'){
				alpha[i][4] += 1;
			}else if(str[i][j] == 'f'){
				alpha[i][5] += 1;
			}else if(str[i][j] == 'g'){
				alpha[i][6] += 1;
			}else if(str[i][j] == 'h'){
				alpha[i][7] += 1;
			}else if(str[i][j] == 'i'){
				alpha[i][8] += 1;
			}else if(str[i][j] == 'j'){
				alpha[i][9] += 1;
			}else if(str[i][j] == 'k'){
				alpha[i][10] += 1;
			}else if(str[i][j] == 'l'){
				alpha[i][11] += 1;
			}else if(str[i][j] == 'm'){
				alpha[i][12] += 1;
			}else if(str[i][j] == 'n'){
				alpha[i][13] += 1;
			}else if(str[i][j] == 'o'){
				alpha[i][14] += 1;
			}else if(str[i][j] == 'p'){
				alpha[i][15] += 1;
			}else if(str[i][j] == 'q'){
				alpha[i][16] += 1;
			}else if(str[i][j] == 'r'){
				alpha[i][17] += 1;
			}else if(str[i][j] == 's'){
				alpha[i][18] += 1;
			}else if(str[i][j] == 't'){
				alpha[i][19] += 1;
			}else if(str[i][j] == 'u'){
				alpha[i][20] += 1;
			}else if(str[i][j] == 'v'){
				alpha[i][21] += 1;
			}else if(str[i][j] == 'w'){
				alpha[i][22] += 1;
			}else if(str[i][j] == 'x'){
				alpha[i][23] += 1;
			}else if(str[i][j] == 'y'){
				alpha[i][24] += 1;
			}else if(str[i][j] == 'z'){
				alpha[i][25] += 1;
			}
		}
	}

	int num[26];

	for(int i = 0; i < 26; ++i){
		num[i] = 50;

		for(int j = 0; j < n; ++j){
			if(alpha[j][i] < num[i]){
				num[i] = alpha[j][i];
			}
		}
		
		if(num[i] != 0){
			if(i == 0){
				for(int j = 0; j < num[i]; ++j){
					cout << 'a';
				}
			}else if(i == 1){
				for(int j = 0; j < num[i]; ++j){
					cout << 'b';
				}
			}else if(i == 2){
				for(int j = 0; j < num[i]; ++j){
					cout << 'c';
				}
			}else if(i == 3){
				for(int j = 0; j < num[i]; ++j){
					cout << 'd';
				}
			}else if(i == 4){
				for(int j = 0; j < num[i]; ++j){
					cout << 'e';
				}
			}else if(i == 5){
				for(int j = 0; j < num[i]; ++j){
					cout << 'f';
				}
			}else if(i == 6){
				for(int j = 0; j < num[i]; ++j){
					cout << 'g';
				}
			}else if(i == 7){
				for(int j = 0; j < num[i]; ++j){
					cout << 'h';
				}
			}else if(i == 8){
				for(int j = 0; j < num[i]; ++j){
					cout << 'i';
				}
			}else if(i == 9){
				for(int j = 0; j < num[i]; ++j){
					cout << 'j';
				}
			}else if(i == 10){
				for(int j = 0; j < num[i]; ++j){
					cout << 'k';
				}
			}else if(i == 11){
				for(int j = 0; j < num[i]; ++j){
					cout << 'l';
				}
			}else if(i == 12){
				for(int j = 0; j < num[i]; ++j){
					cout << 'm';
				}
			}else if(i == 13){
				for(int j = 0; j < num[i]; ++j){
					cout << 'n';
				}
			}else if(i == 14){
				for(int j = 0; j < num[i]; ++j){
					cout << 'o';
				}
			}else if(i == 15){
				for(int j = 0; j < num[i]; ++j){
					cout << 'p';
				}
			}else if(i == 16){
				for(int j = 0; j < num[i]; ++j){
					cout << 'q';
				}
			}else if(i == 17){
				for(int j = 0; j < num[i]; ++j){
					cout << 'r';
				}
			}else if(i == 18){
				for(int j = 0; j < num[i]; ++j){
					cout << 's';
				}
			}else if(i == 19){
				for(int j = 0; j < num[i]; ++j){
					cout << 't';
				}
			}else if(i == 20){
				for(int j = 0; j < num[i]; ++j){
					cout << 'u';
				}
			}else if(i == 21){
				for(int j = 0; j < num[i]; ++j){
					cout << 'v';
				}
			}else if(i == 22){
				for(int j = 0; j < num[i]; ++j){
					cout << 'w';
				}
			}else if(i == 23){
				for(int j = 0; j < num[i]; ++j){
					cout << 'x';
				}
			}else if(i == 24){
				for(int j = 0; j < num[i]; ++j){
					cout << 'y';
				}
			}else if(i == 25){
				for(int j = 0; j < num[i]; ++j){
					cout << 'z';
				}
			}
		}
	}

	cout << "\n";

	return 0;
}