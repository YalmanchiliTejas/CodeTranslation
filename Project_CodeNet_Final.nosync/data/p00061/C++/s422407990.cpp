#include<map>
#include<cstdio>

using namespace std;

int main()
{
	bool ans[31]={false};
	map<int,int> data;
	int id,score;
	for(int i=0;~scanf("%d,%d",&id,&score),id||score;i++){
		ans[score]=true;
		data.insert(make_pair(id,score));
	}

	int rank[31];
	for(int i=30,r=1;i>=0;i--){
		if(ans[i])	rank[i]=r++;
	}

	while(~scanf("%d",&id))printf("%d\n",rank[data[id]]);

	return 0;
}