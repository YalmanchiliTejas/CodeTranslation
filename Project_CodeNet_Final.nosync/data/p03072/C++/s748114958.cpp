#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N;
	cin >>N;
	
	vector<int> heights(N);
	for(int i=0; i<N; i++){
		
		cin >>heights.at(i);
		
	}
	
	int max=0;
	
	int count=0;
	
	for(int i=0; i<N; i++){
		
		if(heights.at(i)>=max){
			
			max=heights.at(i);
			count++;
			
		}
		
	}
	
	cout <<count <<endl;
	
}