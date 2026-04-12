#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define lli long long int
#define REP(i,n) for(int i=0;i<n;i++)
#define DEBUG 0

int main(){

	lli n,m;
	cin>>n>>m;
	map<lli,vector<lli>> g;
	REP(i,m){
		lli tmpA,tmpB;
		cin>>tmpA>>tmpB;
		g[tmpA].push_back(tmpB);
		g[tmpB].push_back(tmpA);
	}

	queue<lli> q;
	queue<lli> f;

	q.push(1);
	f.push(1);
	lli ansCnt=0;
	while(q.size()){
		lli top = q.front();
		lli topF = f.front();
		q.pop();
		f.pop();
		lli flag=0;
		for(auto &e:g[top]){
			if(DEBUG)cout<<e<<" ";
			if(DEBUG)cout<<topF<<" "<< (1<<(e-1))<<endl;
			if((topF & 1<<(e-1)) == 0){
				if(DEBUG)cout<<topF<<" "<< (1<<(e-1))<<endl;
				q.push(e);
				f.push(topF|1<<(e-1));
				flag=1;
			}
		}
		if(flag==0){
			lli ansFlag=0;
			REP(i,n){
				if((topF & (1<<i)) ==0){
					ansFlag=1;
					break;
				}
			}
			if(ansFlag==0){
				ansCnt++;
			}
		}
	}

	cout<<ansCnt<<endl;

	return 0;
}