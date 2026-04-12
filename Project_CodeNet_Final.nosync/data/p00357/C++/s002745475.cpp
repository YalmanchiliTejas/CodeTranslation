#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

int main (void){
	int N;
	int MAX = 0;
	int MIN = 0;
	bool task1 = false;
	bool task2 = false;
	static int d[300000];
	static int should[300000];
	
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> d[i];
	}
	int plan = 0;
	while(1){
		if(d[plan]+(plan*10) > MAX){
			if(d[plan] > 9){
				MAX = d[plan]+(plan*10);
				if(MAX >= (N-1)*10){
					task1 = true;
					break;
				}
			}
		}
		if(MAX < (plan+1)*10){
			break;
		}
		plan++;
	}
	
	if(task1){
		plan = N-1;
		while(1){
			if(d[plan] + (N-plan-1)*10 > MIN){
				if(d[plan] > 9){
					MIN = d[plan]+(N-plan-1)*10;
					if(MIN >= (N-1)*10){
						task2 = true;
						break;
					}
				}
			}
			if(MIN < (N-plan)*10){
				break;
			}
			plan--;
		}
	}
	
	if(task2){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	return 0;
}