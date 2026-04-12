#include<iostream>
#include<algorithm>

#define N 64

int n;
int S[N][26];

int input(){
	char str[N];
	for( int i = 0; i < N; i++ ){
		for( int j = 0; j < 26; j++ ){
			S[i][j] = 0;
		}
	}
	std::cin >> n;
	for( int i = 0; i < n; i++ ){
		std::cin >> str;
		for( int j = 0; str[j] != '\0'; j++ ){
			S[i][str[j]-'a']++;
		}
	}
	return 0;
}

int run(){
	int m;
	for( int i = 0; i < 26; i++ ){
		m = S[0][i];
		for( int j = 1; j < n; j++ ){
			if( S[j][i] < m ){
				m = S[j][i];
			}
		}
		for( int k = 0; k < m; k++ ){
			std::cout << (char)('a'+i);
		}
	}
	std::cout << std::endl;
	return 0;
}

int main(){
	input();
	run();
	return 0;
}
