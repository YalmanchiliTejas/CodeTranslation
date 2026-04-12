#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

int dice[]={1,2,3,4,5,6};
enum{UP,FRONT,RIGHT,LIGHT,BACK,DOWN};//ツ湘」ツ、ツ偲ィツ前ツ、ツ右ツ、ツ債カツ、ツ可慊、ツ可コ

void init(){
	for(int i=0;i<6;i++){
		dice[i]=i+1;
	}
}

void north(){
	int t=dice[UP];
	dice[UP]=dice[FRONT];
	dice[FRONT]=dice[DOWN];
	dice[DOWN]=dice[BACK];
	dice[BACK]=t;
}

void east(){
	int t=dice[UP];
	dice[UP]=dice[LIGHT];
	dice[LIGHT]=dice[DOWN];
	dice[DOWN]=dice[RIGHT];
	dice[RIGHT]=t;
}

void south(){
	int t=dice[UP];
	dice[UP]=dice[BACK];
	dice[BACK]=dice[DOWN];
	dice[DOWN]=dice[FRONT];
	dice[FRONT]=t;
}

void west(){
	int t=dice[UP];
	dice[UP]=dice[RIGHT];
	dice[RIGHT]=dice[DOWN];
	dice[DOWN]=dice[LIGHT];
	dice[LIGHT]=t;
}

void right(){
	int t=dice[FRONT];
	dice[FRONT]=dice[RIGHT];
	dice[RIGHT]=dice[BACK];
	dice[BACK]=dice[LIGHT];
	dice[LIGHT]=t;
}

void left(){
	int t=dice[FRONT];
	dice[FRONT]=dice[LIGHT];
	dice[LIGHT]=dice[BACK];
	dice[BACK]=dice[RIGHT];
	dice[RIGHT]=t;
}

int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		
		int sum=0;
		init();
		string ss;
		for(int i=0;i<n;i++){
			cin>>ss;
			if(ss=="North")north();
			if(ss=="East")east();
			if(ss=="South")south();
			if(ss=="West")west();
			if(ss=="Right")right();
			if(ss=="Left")left();
			//cout<<"UP "<<dice[UP]<<endl;
			sum+=dice[UP];
		}
		cout<<sum+1<<endl;
	}
}