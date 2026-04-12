#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define max_c 50
using namespace std;

int n;
char S[51];
int num_of_alphabet[26], min_num_of_alphabet[26];

void getMinNum(){
	for(int i = 0; i < 26; i++){
		num_of_alphabet[i] = 0;
	}
	for(int i = 0; i < strlen(S); i++){
		num_of_alphabet[S[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		//cout << i << " " << num_of_alphabet[i] << endl;
		if(num_of_alphabet[i] < min_num_of_alphabet[i]){
			min_num_of_alphabet[i] = num_of_alphabet[i];
		}
	}
}

void printMax(){
	//cout << "come into printMax" << endl;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < min_num_of_alphabet[i] ;j++){
			printf("%c", i + 'a');
		}
	}
}

int main(void){
	for(int i = 0; i < 26; i++){
		min_num_of_alphabet[i] = max_c + 1;
		//cout << min_num_of_alphabet[i] ;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> S;
		getMinNum();
	}

	printMax();

	return 0;
}
