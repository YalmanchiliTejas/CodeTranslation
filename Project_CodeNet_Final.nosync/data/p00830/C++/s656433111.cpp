#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class data{
public:
	string str;
	int id;
	data(){}
	data(string ss,int index){
		str=ss;
		id=index;
	}
};

int n,m;
string str[101];
vector<data> G[100001];
int parent[100001];
string name[100001];

int check(string str){
	int now=0;
	string str2="";
	for(int j=1;j<str.size();j++){
		if(str[j]=='/'){
			if(str2==".");
			else if(str2==".."){
				if(now==0)return -1;
				now=parent[now];
			}else{
				int k;
				for(k=0;k<G[now].size();k++){
					if(G[now][k].str==str2){
						now=G[now][k].id;
						break;
					}
					if(k==G[now].size()-1)return -1;
				}
				if(G[now].size()==0)return -1;
			}
			str2="";
		}else{
			str2+=str[j];
		}
	}
	if(str2==".");
	else if(str2==".."){
		if(now==0)return -1;
		now=parent[now];
	}else if(str2!=""){
		int k;
		for(k=0;k<G[now].size();k++){
			if(G[now][k].str==str2){
				now=G[now][k].id;
				break;
			}
			if(k==G[now].size()-1)return -1;
		}
	}
	for(int k=0;k<G[now].size();k++){
		if(G[now][k].str=="index.html" && G[G[now][k].id].size()==0){
			now=G[now][k].id;
			break;
		}
		if(k==G[now].size()-1 && str[str.size()-1]=='/')return -1;
	}
	if(G[now].size()!=0)return -1;
	return now;
}
int all;
int main(void){
	while(1){
		scanf("%d %d",&n,&m);
		if(n+m==0)break;
		for(int i=0;i<=all;i++){
			G[i].clear();
		}
		memset(parent,0,sizeof(parent));
		for(int i=0;i<n;i++){
			cin >> str[i];
		}
		all=0;
		for(int i=0;i<n;i++){
			string str2="";
			int now=0;
			for(int j=1;j<str[i].size();j++){
				if(str[i][j]=='/'){
					if(str2==".");
					else if(str2==".."){
						now=parent[now];
					}else{
						int k;
						for(k=0;k<G[now].size();k++){
							if(G[now][k].str==str2)break;
						}
						if(k!=G[now].size()){
							now=G[now][k].id;
							str2="";
							continue;
						}
						parent[all+1]=now;
						name[all+1]=str2;
						G[now].push_back(data(str2,all+1));
						now=all+1;
						all++;
					}
					str2="";
				}else{
					str2+=str[i][j];
				}
			}
			if(str2!="" && str2!="." && str2!=".."){
				int k;
				for(k=0;k<G[now].size();k++){
					if(G[now][k].str==str2)break;
				}
				if(k!=G[now].size())continue;
				parent[all+1]=now;
				name[all+1]=str2;
				G[now].push_back(data(str2,all+1));
				now=all+1;
				all++;
			}
		}
		for(int i=0;i<m;i++){
			string str,str2;
			cin >> str;
			cin >> str2;
			int now=check(str);
			int now2=check(str2);
			//printf("%d %d\n",now,now2);
			if(now==-1|| now2==-1)printf("not found\n");
			else printf("%s\n",now==now2?"yes":"no");
		}
	}
	return 0;
}