#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N;
  	string S; 
	cin >> N >> S; 
	S = S + S.at(0); 
	bool SS[100010] = {}, SW[100010] = {}, WS[100010] = {}, WW[100010] = {};
	SS[0] = 0, SS[1] = 0, SW[0] = 0, SW[1] = 1;
	WS[0] = 1, WS[1] = 0, WW[0] = 1, WW[1] = 1; 
	for(int i = 2; i <= N + 1; i++){
		if((SS[i-1] == 0 && S.at(i-1) == 'o') || (SS[i-1] == 1 && S.at(i-1) == 'x')){SS[i] = SS[i-2]; 
        }
      	else if((SS[i-1] == 1 && S.at(i-1) == 'o') || (SS[i-1] == 0 && S.at(i-1) == 'x')){SS[i] = 1-SS[i-2];
        }
		if((SW[i-1] == 0 && S.at(i-1) == 'o') || (SW[i-1] == 1 && S.at(i-1) == 'x')){SW[i] = SW[i-2]; 
        }
      	else if((SW[i-1] == 1 && S.at(i-1) == 'o') || (SW[i-1] == 0 && S.at(i-1) == 'x')){SW[i] = 1-SW[i-2];
        }
        if((WS[i-1] == 0 && S.at(i-1) == 'o') || (WS[i-1] == 1 && S.at(i-1) == 'x')){WS[i] = WS[i-2]; 
        }
      	else if((WS[i-1] == 1 && S.at(i-1) == 'o') || (WS[i-1] == 0 && S.at(i-1) == 'x')){WS[i] = 1-WS[i-2];
        }
        if((WW[i-1] == 0 && S.at(i-1) == 'o') || (WW[i-1] == 1 && S.at(i-1) == 'x')){WW[i] = WW[i-2]; 
        }
      	else if((WW[i-1] == 1 && S.at(i-1) == 'o') || (WW[i-1] == 0 && S.at(i-1) == 'x')){WW[i] = 1-WW[i-2];
        }
	} 
	if(SS[0] == SS[N] && SS[1] == SS[N + 1]){
		for(int i = 0; i < N; i++){
			if(SS[i] == 0){
				cout << 'S'; 
			}
			else if(SS[i] == 1){
				cout << 'W'; 
			}
		}
      cout << endl; 
    }
	else if(SW[0] == SW[N] && SW[1] == SW[N + 1]){
		for(int i = 0; i < N; i++){
			if(SW[i] == 0){
				cout << 'S'; 
			}
			else if(SW[i] == 1){
				cout << 'W'; 
			}
		}
      cout << endl; 
	}
	else if(WS[0] == WS[N] && WS[1] == WS[N + 1]){
		for(int i = 0; i < N; i++){
			if(WS[i] == 0){
				cout << 'S'; 
			}
			else if(WS[i] == 1){
				cout << 'W'; 
			}
		}
      cout << endl; 
    }
	else if(WW[0] == WW[N] && WW[1] == WW[N + 1]){
		for(int i = 0; i < N; i++){
			if(WW[i] == 0){
				cout << 'S'; 
			}
			else if(WW[i] == 1){
				cout << 'W'; 
			}
		}
      cout << endl; 
	}
	else cout << "-1" << endl; 
}