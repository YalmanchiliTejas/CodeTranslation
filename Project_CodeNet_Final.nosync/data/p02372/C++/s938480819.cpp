#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
#include<list>
#include<cmath>
#include<iomanip>
#include<queue>
#include<functional>
#include<climits>
#include<iterator>
#include<unordered_map>

//#include"GraphAlgorithm.hpp"
//#include"DataStructure.hpp"
//using namespace graph_algorithm;
//using namespace data_structure;

using namespace std;

const double pi=4*atan(1.0);

int mod=1000000007;

//int(leaf),int(height)
pair<int,int> get_height_dfs_helper(int root,const vector<vector<pair<int,int>>>& WeightEdges,vector<bool>& IsVisit,vector<int>& Parents){
	if(WeightEdges.empty() || Parents.empty() || WeightEdges.size()!=Parents.size() || root<0 || WeightEdges.size()-1<root)return make_pair(-1,-1);

	IsVisit[root]=true;
	pair<int,int> ans=make_pair(-1,-1);
	for(const auto& val:WeightEdges[root]){
		if(!IsVisit[val.first]){
			Parents[val.first]=root;
			auto tmp=get_height_dfs_helper(val.first,WeightEdges,IsVisit,Parents);
			if(ans.second<tmp.second+val.second){
				tmp.second+=val.second;
				ans=tmp;
			}
		}
	}

	if(ans.first<0)return make_pair(root,0);
	else return ans;
}

//int(leaf),int(height)
pair<int,int> get_height_dfs(int root,const vector<vector<pair<int,int>>>& WeightEdges,vector<int>& Parents){
	if(WeightEdges.empty() || root<0 || WeightEdges.size()-1<root)return make_pair(-1,-1);

	vector<bool> IsVisit(WeightEdges.size(),false);
	return get_height_dfs_helper(root,WeightEdges,IsVisit,Parents);
}

int main() {
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> Edges(n);
	for(int i=0;i<n-1;++i){
		int u,v,w;
		cin>>u>>v>>w;
		Edges[u].push_back(make_pair(v,w));
		Edges[v].push_back(make_pair(u,w));
	}

	vector<int> Parents(Edges.size(),-1);
	auto farthest=get_height_dfs(0,Edges,Parents);

	for(auto& val:Parents)val=-1;
	farthest=get_height_dfs(farthest.first,Edges,Parents);

	//int(vertex),int(Height)
	vector<pair<int,int>> FarthestPath;
	FarthestPath.reserve(Edges.size());
	int vertex=farthest.first;
	int length=0;
	while(vertex>=0){
		FarthestPath.push_back(make_pair(vertex,max(length,farthest.second-length)));
		
		for(const auto& val:Edges[vertex]){
			if(val.first==Parents[vertex]){
				length+=val.second;
			}
		}

		vertex=Parents[vertex];
	}

	vector<bool> IsVisit(Edges.size(),false);
	for(const auto& val:FarthestPath)
		IsVisit[val.first]=true;

	vector<int> Ans(Edges.size(),0);
	for(const auto& val:FarthestPath){
		
		queue<pair<int,int>> Q;
		Q.push(val);
		while(!Q.empty()){
			auto now=Q.front();
			Q.pop();
			Ans[now.first]=now.second;

			for(const auto& edge:Edges[now.first]){
				if(!IsVisit[edge.first]){
					IsVisit[edge.first]=true;
					Q.push(make_pair(edge.first,now.second+edge.second));
					Ans[edge.first]=now.second+edge.second;
				}
			}
		}
	}

	for(const auto& val:Ans){
		cout<<val<<"\n";
	}

	//system("pause");
	return 0;
}