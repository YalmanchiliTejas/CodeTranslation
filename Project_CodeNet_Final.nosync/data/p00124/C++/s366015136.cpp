#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<functional>
using namespace std;

struct Team{
	string name;
	int n,s;
	bool operator <(const Team t)const{
		if(s==t.s) return n<t.n;
		return s>t.s;
	}
};

int main(){
	Team T[10];
	int N,W,L,D;
	for(int ds=0; cin>>N,N; ds++){
		if(ds!=0) puts("");
		for(int i=0;i<N;i++){
			cin>>T[i].name>>W>>L>>D;
			T[i].n = i; T[i].s = W*3+D;
		}
		sort(T,T+N);
		for(int i=0;i<N;i++){
			cout<<T[i].name;
			printf(",%d\n",T[i].s);
		}
	}
}