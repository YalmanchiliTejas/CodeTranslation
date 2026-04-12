#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

struct ver{
	int key;
	int x;
	int y;
};

struct edge{
	int cost;
	int v1;
	int v2;
};

int main(){
	int n;
	int answer=0;
	std::vector<ver> verList;
	std::vector<std::vector<edge>> edgeList;
	std::priority_queue<edge, std::vector<edge>, std::function<bool(edge, edge)>> qList(
		[](edge a, edge b){return a.cost > b.cost;});

	std::cin>>n;
	verList.resize(n);
	edgeList.resize(n);

	for(int i=0; i<n; i++){
		std::cin>>verList[i].x>>verList[i].y;
		verList[i].key= i;
	}

	std::sort(verList.begin(), verList.end(),
		[](const ver& a, const ver& b){return a.x<b.x;});

	for(int i=1; i<n; i++){
		edgeList[verList[i-1].key].push_back({verList[i].x - verList[i-1].x ,verList[i-1].key, verList[i].key});
		edgeList[verList[i].key].push_back({verList[i].x - verList[i-1].x ,verList[i-1].key, verList[i].key});
	}

	std::sort(verList.begin(), verList.end(),
		[](const ver& a, const ver& b){return a.y<b.y;});

	for(int i=1; i<n; i++){
		edgeList[verList[i-1].key].push_back({verList[i].y - verList[i-1].y ,verList[i-1].key, verList[i].key});
		edgeList[verList[i].key].push_back({verList[i].y - verList[i-1].y ,verList[i-1].key, verList[i].key});
	}


	int edgeCount= 0;
	std::vector<int> isSelected(n, -1);
	isSelected[0]= 1;
	for(int i=0; i< edgeList[0].size(); i++)
		qList.push(edgeList[0][i]);

	while(1){
		if(edgeCount>= n-1)
			break;
		
		edge e= qList.top();
		qList.pop();

		if(isSelected[e.v1] * isSelected[e.v2] >0)
			continue;
		
		if(isSelected[e.v1]<0){
			isSelected[e.v1]= 1;
			answer+=e.cost;
			for(int i=0; i< edgeList[e.v1].size(); i++)
				qList.push(edgeList[e.v1][i]);
			edgeCount++;
		}else if(isSelected[e.v2]<0){
			isSelected[e.v2]= 1;
			answer+=e.cost;
			for(int i=0; i< edgeList[e.v2].size(); i++)
				qList.push(edgeList[e.v2][i]);
			edgeCount++;
		}

	} 
/*------------------------------*/
//	for(int i=0; i< edgeList.size(); i++)
//		std::cout<< edgeList[i].cost<<","<<edgeList[i].v1<<","<<edgeList[i].v2<<std::endl;
	std::cout<<answer<<std::endl;



	return 0;
}