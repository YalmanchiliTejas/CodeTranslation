#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int>m;
	vector<int>v;
	int a,b;
	while(scanf("%d,%d",&a,&b)){
		if(a==0&&b==0)break;
		m.insert(make_pair(a,b));
		
		int flg=1;
		for(int i=0;i<v.size();i++){
			if(v[i]==b){
				flg=0;
				break;
				}
			}
			
		if(flg==1)v.push_back(b);	
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		int c;
		while(cin>>c){
			int d=m[c];
			
			for(int i=0;i<v.size();i++){
				if(v[i]==d){cout<<i+1<<endl;}
				}
			}
			return 0;
	}