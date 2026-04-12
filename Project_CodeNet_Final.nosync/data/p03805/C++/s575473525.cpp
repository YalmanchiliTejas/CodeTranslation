#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

using namespace std;
#define NMAX 8
int N,M;
bool graph[NMAX][NMAX];
int ct=0;

void allsr(int num,int coun,vector<bool> used){
	used[num] = true;
	if(coun == N){
		ct++;
		return;
	}
	rep(i,0,N){
		if(graph[num][i] == true && !used[i]){
			allsr(i,coun+1,used);
		}
	}
}

int main(){
	cin >> N >> M;
	int a,b;
	vector<bool> used(N);
	rep(i,0,N){
		used[i] = false;
		rep(j,0,N){
			graph[i][j]=false;
		}
	}

	rep(i,0,M){
		cin >> a >> b;
		graph[a-1][b-1] = true;
		graph[b-1][a-1] = true;
	}
	allsr(0,1,used);
	cout << ct << endl;
}
