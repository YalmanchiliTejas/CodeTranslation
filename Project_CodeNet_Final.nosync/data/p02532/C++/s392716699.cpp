#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 999999
#define rep(i,j) for(int i=0;i<(j);++i)
#define reps(i,j,k) for(int i=j;i<k;++i)
typedef long long ll;
typedef unsigned long long ull;

int main(){
	stack <string> b[128];
	 int n;
	 cin >> n;
	 string str;
	 while(cin >> str , str != "quit"){
	 	if(str == "push"){
	 		int num;
	 		string x;
	 		cin >> num >> x;
	 		b[num].push(x); 
	 	}
	 	else if(str == "pop"){
	 		int num;
	 		cin >> num;
	 		cout << b[num].top() << endl;
	 		b[num].pop();
	 	}
	 	else if(str == "move"){
	 		int from,to;
	 		cin >> from >> to;
	 		string m;
	 		m = b[from].top();
	 		b[from].pop();
	 		b[to].push(m);
	 	}
	 }
	return 0;
}