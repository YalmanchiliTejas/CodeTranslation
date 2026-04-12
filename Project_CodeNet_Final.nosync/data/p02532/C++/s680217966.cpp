
#include<bits/stdc++.h>

using namespace std;
#define PI acos(-1)

int main(){
	int n;
	cin>>n;
	stack<char>stck[n];
	string order;
	char ms;
	int num;
	
	while(cin>>order){
		if(order=="push"){
			cin>>num>>ms;
			stck[num-1].push(ms);
		}
		if(order=="pop"){
			cin>>num;
			cout<<stck[num-1].top()<<endl;
			stck[num-1].pop();
		}
		if(order=="quit"){
			break;
		}
		if(order=="move"){
			int move;
			cin>>num>>move;
			stck[move-1].push(stck[num-1].top());
			stck[num-1].pop();
		}
	}
}