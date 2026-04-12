#include <iostream>
#include <cstdio>
//#define DEBUG
using namespace std;
const int MAX = 1e5 + 10;
int arr[MAX];
int answer[MAX];
char char_answer[MAX];
int main(int argc, char *argv[]) {
	int N;
	while(cin >> N) {
		scanf("%s", char_answer + 1);
		for(int i = 1; i <= N; i++) {
			
			
			if(char_answer[i] == 'o')
				answer[i] = 1;
			else {
				answer[i] = 0;
			}
			
			#ifdef DEBUG 
			cout << char_answer[i];
			#endif
		}
		#ifdef DEBUG 
		cout << endl;
		#endif
		//cases: 1 sheet 0 wolf
		int flag = 0;
		for(int cases = 0; cases < 2; cases++) {
			arr[1] = cases;
			for(int i = 0; i < 2; i++) {
				arr[0] = i;
				for(int j = 1; j <= N; j++) {
					if(arr[j]) { // j is sheet
						if(answer[j]) // answer is o
							arr[j + 1] = arr[j - 1];
						else {
							arr[j + 1] = arr[j - 1] ^ 1;
						}
					}else { // j is wolf
						if(answer[j])// answer is o
							arr[j + 1] = arr[j - 1] ^ 1;
						else {
							arr[j + 1] = arr[j - 1];
						}
					}
				}
				#ifdef DEBUG
				for(int l = 0; l <= N + 1; l++) {
					cout << arr[l];
					
				}
				cout << endl;
				#endif
				if(arr[0] == arr[N] && arr[N + 1] == arr[1] && flag == 0) {
					for(int i = 1; i <= N; i++) {
						if(arr[i])
							cout << "S";
						else {
							cout << "W";
						}
					}
					cout << endl;
					flag = 1;
					
				}
			}
		}
		if(flag == 0)
			cout << -1 << endl;
		
	}
}