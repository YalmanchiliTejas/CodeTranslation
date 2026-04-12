#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#include<chrono>
using namespace std;
typedef long long ll;
vector<int>e[200];
int main(){
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		s+='0';
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			s[i]='1';
			s[j]='1';
			cout<<"? "+s<<endl;
			s[i]='0';
			s[j]='0';
			int r;
			cin>>r;
			if(r==1){
				e[i].push_back(j);
			}
		}
	}
	cout<<"!";
	for(int i=0;i<n;i++){
		for(int j=0;j<e[i].size();j++){
			if(e[i][j]>i){
				cout<<" ("+to_string(i)+','+to_string(e[i][j])+')';
			}
		}
	}
	cout<<endl;
}
