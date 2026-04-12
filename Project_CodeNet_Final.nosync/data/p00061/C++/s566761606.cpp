#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int main(){
	int n,m,c=1;
	vector<int> key[31];
	map<int,int> data;
	while(scanf("%d,%d",&n,&m),n||m)key[m].push_back(n);
	for(int i=30;i>=0;i--){
		if(key[i].size()){
			for(int j=0;j<key[i].size();j++)data[key[i][j]]=c;
			c++;
		}
	}
    int l;
	while(cin>>l)cout<<data[l]<<endl;
    
    return(0);
}