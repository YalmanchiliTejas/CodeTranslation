#include<iostream>
#include<string>

std::pair<std::string,int> team[10];

int main()
{
	int n,win,lose,draw,point;
	std::string name;
	bool first=true;
	
	while(1)
	{
		std::cin>>n;
		if(n==0)break;
		
		for(int i=0;i<n;i++)
		{
			std::cin>>name>>win>>lose>>draw;
			point=win*3+draw;
			team[i].first=name;
			team[i].second=point;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i;j>0&&team[j].second>team[j-1].second;j--)
			{
				std::pair<std::string,int> temp;
				temp=team[j];
				team[j]=team[j-1];
				team[j-1]=temp;
			}
		}
		
		if(first){first=false;}
		else{std::cout<<std::endl;}
		for(int i=0;i<n;i++)
		{
			std::cout<<team[i].first<<','<<team[i].second<<std::endl;
		}
	}
	return 0;
}