#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(){
	int N,dam;
	vector<int> p;
	int cmp=0;
	bool t=true;
	for(int i=0;i<12;i++){
		scanf("%d",&dam);
		p.push_back(dam);
	}
	sort(p.begin(),p.end());
	for(int i=0;i<12;i++){
		if(i%4==0)
		cmp=p[i];
		if(p[i]!=cmp){
			t=false;
			break;
		}
	}
	if(t==true)
	printf("yes\n");
	else
	printf("no\n");
}
