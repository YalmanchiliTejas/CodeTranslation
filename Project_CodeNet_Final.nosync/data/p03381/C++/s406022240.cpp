#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

int main(){
	int midLeft;
	int midRight;

	int n;
	std::vector<int> xList;
	std::vector<int> sortedList;

	std::cin>>n;
	xList.resize(n);
	for(int i=0; i<n; i++)
		std::cin>>xList[i];

	std::copy(xList.begin(), xList.end(), std::back_inserter(sortedList));

	std::sort(sortedList.begin(), sortedList.end());
	midRight= sortedList[sortedList.size()/2];
	midLeft= sortedList[sortedList.size()/2 -1];

	for(int i=0; i<n; i++){
		if(xList[i]<=midLeft)
			std::cout<<midRight<<std::endl;
		else
			std::cout<<midLeft<<std::endl;
	}

	return 0;
	
}