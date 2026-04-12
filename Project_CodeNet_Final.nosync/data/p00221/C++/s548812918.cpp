#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<stdio.h>
using namespace std;
const int MAX_M = 1010;
const int MAX_N = 10010;
#define REP(i, j) for(int i = 0; i < j; i++)
#define FOR(i, j, k) for(int i = j; i < k; i++)

int main(){
	int m, n;
	while(cin >>m >>n && (m || n)){
		int human[MAX_M] = {false};
		REP(i, m + 1) human[i] = true;
		human[0] = false;


		int h = m;
		int now = 1;
		FOR(i, 1, n + 1){
			string str; cin >>str;
			if(h == 1) continue;
			while(!human[now]){
				now++;
				if(now > m) now = 0;
			}
			if(i % 3 == 0 && i % 5 == 0){
				if(str != "FizzBuzz"){
					human[now] = false;
					h--;
				}
			} else if(i % 3 == 0){
				if(str != "Fizz"){
					human[now] = false;
					h--;
				}
			} else if(i % 5 == 0){
				if(str != "Buzz"){
					human[now] = false;
					h--;
				}
			} else{
				int sum = 0;
				sscanf(str.c_str(), "%d", &sum);
				/*
				bool okFlg = true;
				char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
				REP(j, str.length()){
					int flg = false;
					REP(k, 10){
						if(str[j] == num[k]) flg = true;
					}
					if(!flg) okFlg = false;
				}
				int sum = 0;
				for(int j = str.length() - 1; j >= 0; j--){
					sum *= 10;
					sum += (int)(str[j] - '0');
				}
				*/
				if(sum != i){
					human[now] = false;
					h--;
				}
			}
			now++;
		}
		stringstream ss;
		bool firFlg = true;
		REP(i, m + 1){
			if(human[i]){
				if(firFlg == true){
					ss <<i;
					firFlg = false;
				}
				else ss <<" " <<i;
			}
		}
		cout <<ss.str() <<endl;
	}
	return 0;
}