#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <sstream>
using namespace std;

int main(void){
	int n;
	while(cin >> n){
		if(n == 0) break;
		int d[4] = {5, 3, 2, 4};
		int head = 1;
		int sum = 0;
		for(int i = 0; i < n; i++){
			string S;
			cin >> S;
			if(S == "South"){
				int b = d[0];
				int a = head;
				d[0] = 7-head;
				head = b;
				d[2] = a;
				sum += head;
			}else if(S == "North"){
				int b = d[2];
				int a = head;
				d[2] = 7-head;
				head = b;
				d[0] = a;
				sum += head;
			}else if(S == "West"){
				int b = d[1];
				int a = head;
				d[1] = 7-head;
				head = b;
				d[3] = a;
				sum += head;
			}else if(S == "East"){
				int b = d[3];
				int a = head;
				d[3] = 7-head;
				head = b;
				d[1] = a;
				sum += head;
			}else if(S == "Left"){
				int save[4];
				for(int j = 0; j < 4; j++)
					save[j] = d[j];
				for(int j = 0; j < 3; j++){
					d[j] = save[j+1];
				}
				d[3] = save[0];
				sum += head;
			}else if(S == "Right"){
				int save[4];
				for(int j = 0; j < 4; j++)
					save[j] = d[j];
				for(int j = 0; j < 3; j++){
					d[j+1] = save[j];
				}
				d[0] = save[3];
				sum += head;
			}
		}
		cout << sum+1 << endl;
	}

}