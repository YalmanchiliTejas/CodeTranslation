#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main(){
	int n,num[2];
	char block,mBlock;
	
	string orderStr[]={"push","pop","move","quit"};
	stack<char> yama[101];
	queue<char> ans;
	
	//yama.reserve(101);
	cin>>n;
	while(true){
		string inputStr;
		cin>>inputStr;
		if(inputStr=="quit"){
			break;
		}
		cin>>num[0];
		if(inputStr=="push"){
			cin>>block;
			yama[num[0]].push(block);
		}
		else if(inputStr=="pop"){
			if(!yama[num[0]].empty()){
				ans.push(yama[num[0]].top());
				yama[num[0]].pop();
			}
		}
		else if(inputStr=="move"){
			cin>>num[1];
			//ans.push(yama[num[0]].top());
			yama[num[1]].push(yama[num[0]].top());
			if(!yama[num[0]].empty()){
				yama[num[0]].pop();
			}
		}
	}
	while(!ans.empty()){
		cout<<ans.front()<<endl;
		ans.pop();
	}
	return 0;
}