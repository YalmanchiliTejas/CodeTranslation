#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>

using namespace std;

map<int,int> team;
priority_queue<int> score;
priority_queue<int> score2;

int main(void){
	int a,b;
	while(1){
		scanf("%d,%d",&a,&b);
		if(a==0 && b==0)break;
		team.insert(map<int,int>::value_type(a,b));
		score.push(b);
	}
	while(~scanf("%d",&a)){
		int t;
		int rank=1;
		t=team[a];
		score2=score;
		bool ch=true;
		while(ch){
			int Us=0;
			if(t==score2.top()){
				cout << rank << endl;
				ch=false;
			}
			Us=score2.top();
			score2.pop();
			if(score2.top()!=Us)rank++;
		}
	}
	return 0;
}