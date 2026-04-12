#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) FOR(i,0,b)
const int INF=1<<30;
using namespace std;
typedef pair<int,int> pr;
typedef vector<int> vi;
char word[100001];
vi edge[100001];
int V,E,a,b;
void search(int num){
	if(num==V)
	return ;
	if(word[num]=='?'){
	bool used[27]={};
	REP(i,edge[num].size())
	if(word[edge[num][i]] !='?')
	used[word[edge[num][i]]-'a']=true;
	REP(i,26)
	if(!used[i]){
		word[num]=i+'a';
		break;
	}
	}
	cout << word[num];
	search(num+1);
	return ;
}
int main() {
	cin >> V >> E;
	REP(i,V)
	cin >> word[i];
	REP(j,E){
	cin >> a >> b;
	edge[a].push_back(b);
	edge[b].push_back(a);
	}
	search(0);
	cout << endl;
	// your code goes here
	return 0;
}
