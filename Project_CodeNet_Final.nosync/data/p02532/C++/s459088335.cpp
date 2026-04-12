#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;


int main(){

	int n;
	cin >> n;

	string stack[n], ans;
	string code;
	char col;
	int i;
	int num;

	while(1){

		cin >> code;
		if(code == "push"){
			cin >> num;
			num--;
			cin >> col;
			stack[num] += col;
		}
		if(code == "pop"){
			cin >> num;
			num--;
			string array;
			for(i=0 ; i<stack[num].size()-1 ; i++){
				array += stack[num][i];
			}
			ans += stack[num][stack[num].size()-1];
			stack[num] = array;
		}
		if(code == "move"){
			int j;
			cin >> num;
			num--;
			cin >> j;
			j--;
			string array;
			stack[j] += stack[num][stack[num].size()-1];
			for(i=0 ; i<stack[num].size()-1 ; i++){
				array += stack[num][i];
			}
			stack[num] = array;
		}
		if(code == "quit"){
			break;
		}

	}

	for(int i=0 ; i<ans.size() ; i++){
		cout << ans[i] << endl;
	}

	return 0;
}