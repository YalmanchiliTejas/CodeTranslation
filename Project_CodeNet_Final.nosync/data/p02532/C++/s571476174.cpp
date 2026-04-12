#include <iostream>
#include <stack>
#include <vector>
#include <string>

const int MAX_M=100;

using namespace std;

int main(){
	stack<char> mountain[MAX_M+1];
	vector<char> out;
	string cmd;
	int no1,no2;
	char color;
	int n;
	cin>>n;
	do{
		cin>>cmd;
		if (cmd!="quit"){
			if (cmd=="push"){
				cin>>no1>>color;
				mountain[no1].push(color);
			}
			else if (cmd=="pop"){
				cin>>no1;
				color=mountain[no1].top();
				mountain[no1].pop();
				out.push_back(color);
			}
			else{
				//move
				cin>>no1>>no2;
				color=mountain[no1].top();
				mountain[no1].pop();
				mountain[no2].push(color);
			}
		}
	}while(cmd!="quit");
	for (int i=0,l=out.size();i<l;i++){
		cout<<out[i]<<endl;
	}
	return 0;
}