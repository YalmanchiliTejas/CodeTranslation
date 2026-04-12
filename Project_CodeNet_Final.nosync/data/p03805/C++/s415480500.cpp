#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int a[M],b[M];
	vector<int> arr[N];
	for(int i=0;i<M;++i){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		arr[a[i]].push_back(b[i]);
		arr[b[i]].push_back(a[i]);
	}
	/*
	for(int i=0;i<N;++i){
		for(int j=0;j<arr[i].size();++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	stack<vector<int> >s;
	vector<int> path;
	path.push_back(0);
	s.push(path);
	int mark[N];
	for(int i=0;i<N;++i)mark[i]=0;
	int ans=0;
	while(!s.empty()){
		vector<int> now=s.top();
		/*
		for(int i=0;i<now.size();++i){
			cout<<now[i]<<" ";
		}
		cout<<endl;
		*/
		s.pop();
		for(int i=0;i<N;++i)mark[i]=0;
		for(int i=0;i<now.size();++i){
			mark[now[i]]=1;
		}
		for(int i=0;i<arr[now[now.size()-1]].size();++i){
			if(mark[arr[now[now.size()-1]][i]]!=1){
				now.push_back(arr[now[now.size()-1]][i]);
				s.push(now);
				now.erase(now.end()-1);
			}
		}
		if(now.size()==N) ans++;
	}
	cout<<ans<<endl;
}
