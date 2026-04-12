#include <iostream>
#include <stack>
#include <string>
using namespace std;
char st[100][1000];
int sp[100];
void push(int p, char c){
	st[p-1][sp[p-1]++] = c;
}
char pop(int p){
	char top = st[p-1][--sp[p-1]];
	return top;
}
int main(){
	string order;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		sp[i] = 0;
	}
	while(cin >> order, order != "quit"){
		if(order == "push"){
			int p;
			char c;
			cin >> p >> c;
			push(p,c);
		}else if(order == "pop"){
			int p;
			cin >> p;
			cout << pop(p) << endl;
		}else if(order == "move"){
			int p1, p2;
			cin >> p1 >> p2;
			push(p2,pop(p1));
		}else break;
	}
	return 0;
}