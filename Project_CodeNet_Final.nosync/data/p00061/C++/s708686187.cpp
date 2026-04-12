#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	int number[100], solved[100];
	int cont = 0;
	int array[100];
	char tmp;
	int input;
	int arrayCont = 0;
	priority_queue<int> qu;

	while(cin >> number[cont] >> tmp >> solved[cont], number[cont] || solved[cont]){
		qu.push(solved[cont]);
		cont++;
	}


 	bool isFirst = true;
	while(!qu.empty()){
		if(isFirst){
			array[arrayCont] = qu.top();
			isFirst = false;
		}
		else {
			if(array[arrayCont-1] != qu.top()) array[arrayCont] = qu.top();
			else arrayCont--;

		}
		qu.pop();
		arrayCont++;
	}

	while(cin >> input){
		for(int i=0; i < cont; i++){
			if(number[i] == input){
				for(int j=0; j < arrayCont; j++){
					if(solved[i] == array[j]){
						cout << j+1 << endl;
					}
				}
			}
		}
	}
}