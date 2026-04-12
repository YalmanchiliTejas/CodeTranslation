#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	int H,W;
	cin>>H>>W;
	
	vector<string> S(H);
	for(int i=0;i<H;i++)cin>>S[i];
	
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	
	while(q.size()!=0){
		pair<int,int> P = q.front();
		q.pop();
		S[P.first][P.second] = '.';
		int cnt = 0;
		for(int i=0;i<4;i++){
			int x = P.second;
			int y = P.first;
			switch(i){
				case 0:{
					x++;
					break;
				}
				case 1:{
					x--;
					break;
				}
				case 2:{
					y++;
					break;
				}
				case 3:{
					y--;
					break;
				}
			}
			if(y<0||y>=H||x<0||x>=W)continue;
			if(S[y][x]=='.')continue;
			if(i==1||i==3){
				cout<<"Impossible"<<endl;
				return 0;
			}
			q.push(make_pair(y,x));
			cnt++;
		}
		if(cnt>=2){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	
	cout<<"Possible"<<endl;
	
	
	
	
	return 0;
}
