#include<bits/stdc++.h>
using namespace std;

#define MAX_N 8
#define MAX_M 28


bool is_in(vector<int> array,int a){
	for(int i=0;i<array.size();i++){
		if(a==array[i])return true;
	}
	return false;
}


int main() {
    int n,m;
	cin >> n >> m;
	vector<int> p[MAX_N];
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >>b;
		a--;b--;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	queue<vector<int> > q;
	int cnt = 0;
	vector<int> v;
	v.push_back(0);
	q.push(v);
	while(q.size()!=0){
		vector<int> v = q.front();
		q.pop();
		for(int i=0;i<p[v.back()].size();i++){
			int cand = p[v.back()][i];
			if(!is_in(v,cand)){
				if(v.size()==n-1){
					cnt++;
				}else{
					vector<int> v2(v.size());
					copy(v.begin(), v.end(), v2.begin());
					v2.push_back(cand);
					q.push(v2);
				}
			}
		}
	}
	
	cout << cnt << endl;
    return 0;
}


