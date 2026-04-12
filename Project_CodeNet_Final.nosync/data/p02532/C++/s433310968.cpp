#include<iostream>
#include<string>
using namespace std;

int main()
{
	char push_block[100][1000];
	char pop_block[100000];
	string op;
	int pop_all=0;
	int top[100]={0};
	long int pop_num=0;
	int area,area2;

	cin>>area;
	cin>>op;
	while(op!="quit"){
		if(op=="push"){
			cin>>area;
			cin>>push_block[area][top[area]];
			top[area]++;
			pop_all++;
		}
		if(op=="pop"){
			cin>>area;
			top[area]--;
			pop_block[pop_num]=push_block[area][top[area]];
			pop_num++;
		}
		if(op=="move"){
			cin>>area>>area2;
			top[area]--;
			push_block[area2][top[area2]] = push_block[area][top[area]];
			top[area2]++;
		}
		cin>>op;
	}
	for(int i=0 ;i<pop_all ;i++) cout<<pop_block[i]<<endl;
}