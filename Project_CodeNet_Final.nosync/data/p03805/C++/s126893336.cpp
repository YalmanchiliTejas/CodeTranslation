#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void search(int i);

int n, m;
vector<int> a, b;
vector<set<int> > to;
vector<int> list;

int main(){
	cin >> n >> m;
	if(n==2){
		cout << 1 << endl;
		return 0;
	}
	a.resize(m);
	b.resize(m);
	for(int i=0; i<m; i++) cin >> a[i] >> b[i];
	
	to.resize(n);
	for(int i=0; i<m; i++){
		to[a[i]-1].insert(b[i]-1);
		to[b[i]-1].insert(a[i]-1);
	}
	
	list.resize(n-1);
	for(int i=0; i<list.size(); i++) list[i]=i+1;
	int ans=0;
	bool flag;
	do{
		flag=1;
		if(to[0].count(list[0])==0) flag=0;
		for(int i=0; i<list.size()-1; i++){
			if(to[list[i]].count(list[i+1])==0) flag=0;
		}
		
		if(flag) ans+=1;
	}while(next_permutation(list.begin(), list.end()));
	
	cout << ans << endl;
	return 0;
}
