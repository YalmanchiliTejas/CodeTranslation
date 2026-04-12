
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef struct pair<ll,int> P;

int main() {

	int n;
	string s;
	cin>>n>>s;
	int ls=s.length();

	queue<string> que;
	que.push(string("SS"));
	que.push(string("WW"));
	que.push(string("SW"));
	que.push(string("WS"));

	while(!que.empty()){
		string s1=que.front();que.pop();
		int l1=s1.length();
		string s2="S";
		string s3="W";
		if(l1>n+1){
			if((s1[0]==s1[n])&&(s1[1]==s1[n+1])){
				cout<<s1.substr(0,n)<<endl;
				return 0;
			}
			continue;
		}
		if(s1[l1-1]=='S'){
			if(s[(l1-1)%n]=='o'){
				if(s1[l1-2]=='S')s1+=s2;
				if(s1[l1-2]=='W')s1+=s3;
			}
			if(s[(l1-1)%n]=='x'){
				if(s1[l1-2]=='S')s1+=s3;
				if(s1[l1-2]=='W')s1+=s2;
			}
		}else{
			if(s[(l1-1)%n]=='x'){
				if(s1[l1-2]=='S')s1+=s2;
				if(s1[l1-2]=='W')s1+=s3;
			}
			if(s[(l1-1)%n]=='o'){
				if(s1[l1-2]=='S')s1+=s3;
				if(s1[l1-2]=='W')s1+=s2;
			}
		}
		que.push(s1);
//		cout<<s1<<endl;
	}
	cout<<"-1"<<endl;
	return 0;
}
