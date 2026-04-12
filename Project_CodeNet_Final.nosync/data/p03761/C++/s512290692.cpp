#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> hoge(26,0);

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		vector<int> fuga(26,0);

		for(auto a:s){
			fuga.at(a-'a')++;
		}

		if(i==0) hoge=fuga;
		else{
			for(int i=0;i<26;i++){
				hoge.at(i)=min(hoge.at(i),fuga.at(i));
			}
		}
	}

	priority_queue<char,vector<char>,greater<char>> pq;

	for(char i='a';i<='z';i++){
		int cnt=hoge.at(i-'a');

		for(int j=0;j<cnt;j++) pq.push(i);
	}

	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}

	cout<<endl;

	return 0;
}
