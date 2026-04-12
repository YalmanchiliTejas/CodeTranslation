#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <cassert>
 
using namespace std; 

int main(){

	int n,m;
	cin>>n>>m;

	vector<vector<bool> > e(n,vector<bool>(n,false));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		e[a][b]=e[b][a]=true;
	}

	vector<int> order(n);
	for(int i=0;i<n;i++) order[i]=i;
	long long res=0;

	do{

		bool ok=true;
		for(int i=0;i<n-1 && ok;i++){
			if(!e[order[i]][order[i+1]]) ok=false;
		}

		if(ok) res++;

	}while(next_permutation(order.begin()+1,order.end()));


	cout<<res<<endl;
}