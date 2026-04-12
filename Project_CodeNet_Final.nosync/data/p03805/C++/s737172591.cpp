#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> used;
int ans = 0;
int verp = 1;
int n;

void bfs(int x){
	if(verp==n){
		ans++;
		return;
	}
	for(int i = 0;i<a.size();i++){
		if(a[i]==x&&used[b[i]]==0){
			used[b[i]]=1;
			verp++;
			bfs(b[i]);
			used[b[i]]=0;
			verp--;
		}else if(b[i]==x&&used[a[i]]==0){
			used[a[i]]=1;
			verp++;
			bfs(a[i]);
			used[a[i]]=0;
			verp--;
		}
		
	}
	return;
	
}


int main(){
	int m;
	cin>>n>>m;
	
	for(int i = 0; i < m;i++){
		int tmpa,tmpb;
		cin>>tmpa>>tmpb;
		tmpa--;
		tmpb--;
		a.push_back(tmpa);
		b.push_back(tmpb);
		used.push_back(0);
	}
	
	used[0]=1;
	bfs(0);
	
	cout<<ans<<endl;
	
	return 0;
}