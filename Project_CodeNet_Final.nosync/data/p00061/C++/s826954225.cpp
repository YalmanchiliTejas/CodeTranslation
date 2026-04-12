#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
	int n,s,rank;
	data(){}
	data(int _n,int _s){
		n=_n; s=_s;
	}
	bool operator<(const data &a)const{
		return s>a.s;
	}
	bool operator==(const data &a)const{
		return s==a.s;
	}
};

int main(){
	vector<data> team;
	int N,S;
	while(scanf("%d,%d",&N,&S),N||S) team.push_back(data(N,S));
	sort(team.begin(),team.end());
	for(int i=0,rank=1;i<team.size();i++){
		if(i!=0 && !(team[i]==team[i-1])) rank++;
		team[i].rank = rank;
	}
	while(cin>>N){
		for(int i=0;i<team.size();i++){
			if(team[i].n==N){
				printf("%d\n",team[i].rank);
				continue;
			}
		}
	}
	return 0;
}