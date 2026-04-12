#include <bits/stdc++.h>
#define range(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) range(i,0,n)
using namespace std;

map<int,int> team;
int ranking[33];

int main(void){
	while(1){
		int num,score;
		scanf("%d,%d",&num,&score);
		if(num==0) break;
		team[num]=score;
		ranking[score]=1;
	}
	for(int i=30;i>=0;i--) ranking[i]+=ranking[i+1];
	while(1){
		int num;
		cin >> num;
		if(cin.eof()) break;
		printf("%d\n",ranking[team[num]]);
	}
	return 0;
}