#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<char> bl[100];
	int s;//選択されているスタック
	char c;//入力された色
	string m;//命令
	vector<char>ans;ans.reserve(1001);
	while(true){
	cin>>m;
	if(m=="quit")break;
		if(m=="push"){
			cin>>s>>c;
			bl[s].push(c);
		}
		if(m=="pop"){
			cin>>s;
			ans.push_back(bl[s].top());
			bl[s].pop();
		}
		if(m=="move"){
			int a,b;char h;//hは移す対象
			cin>>a>>b;
			h=bl[a].top();bl[a].pop();
			bl[b].push(h);
		}
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
	return 0;
}