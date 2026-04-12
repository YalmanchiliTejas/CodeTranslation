#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int main(){
queue <string> ans;
stack <string> mount[100];
int a,b,n;
string tmp,order;
cin>>n;
while(1){
	cin>>order;
	if(order=="push"){
		cin>>a>>tmp;
		mount[a].push(tmp);
	}else if(order=="pop"){
		cin>>a;
		ans.push(mount[a].top());
		mount[a].pop();
	}else if(order=="move"){
		cin>>a>>b;
		mount[b].push(mount[a].top());
		mount[a].pop();
	}else{
		goto END;
	}
}
END:
while(!ans.empty()){
	cout<<ans.front()<<endl;
	ans.pop();
}
return 0;
}