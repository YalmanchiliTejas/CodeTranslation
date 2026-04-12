#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int main(void){
	
	int yama,move1,move2;
	string mere,block,tmp;
	stack<string> robo[101];
	queue<string> ans;
	while(1){
		cin>>mere;
		if(mere=="quit") break;
		if(mere=="push"){
			cin>>yama;
			cin>>block;
			robo[yama].push(block);
		}
		if(mere=="pop"){
			cin>>yama;
			ans.push(robo[yama].top());
			robo[yama].pop();
		}
		if(mere=="move"){
			cin>>move1>>move2;
			robo[move2].push(robo[move1].top());
			robo[move1].pop();
		}
	}
	while(ans.size()!=0){
		cout<<ans.front()<<endl;
		ans.pop();
	}
	cin>>mere;
	return 0;
}