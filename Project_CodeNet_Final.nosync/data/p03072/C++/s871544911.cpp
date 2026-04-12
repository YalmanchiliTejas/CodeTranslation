#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int main() {
	int n,h,max,answer;
	cin>>n;
	max=0;
	answer=0;
	for(int i=0; i<n; i++){
		cin>>h;
		if(max<=h){
			max=h;
			answer+=1;
		}
	}
	
	cout<<answer<<endl;
}
