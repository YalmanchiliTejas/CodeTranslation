#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	stack<char> mountain[100];
	string input;
	int n;
	int mNum;
	char block;


	cin >> n;
	while(cin >> input, input != "quit"){
		if(input == "push"){
			cin >> mNum >> block;
			mountain[mNum].push(block);
		}
		else if(input == "pop"){
			cin >> mNum;
			cout << mountain[mNum].top() << endl;
			mountain[mNum].pop();
		}
		else if(input == "move"){
			cin >> mNum;
			block = mountain[mNum].top();
			mountain[mNum].pop();
			cin >> mNum;
			mountain[mNum].push(block);
		}
	}
}