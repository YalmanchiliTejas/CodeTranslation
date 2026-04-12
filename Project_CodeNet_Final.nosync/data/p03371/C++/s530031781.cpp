#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	
	int a,b,ab;
	int x,y;
	
	cin >> a >> b >> ab;
	cin >> x >> y;
	
	int cost_A= a*x;
	int cost_B= b*y;
	int total_cost=cost_A + cost_B;
	int cost_AB;
	
	for(int i=2;i<=2*max(x,y);i=i+2){
		
		cost_A=max(0,a*(x-i/2));
		cost_B=max(0,b*(y-i/2));
		cost_AB=ab*i;
		
		int now_cost=cost_A + cost_B + cost_AB;
		
		total_cost=min(total_cost,now_cost);
	}
	
	cout << total_cost << endl;
	
	return 0;
}
