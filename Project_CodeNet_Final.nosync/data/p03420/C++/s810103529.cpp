#include<iostream>
#include<vector>
#include<cmath>

int main(){
	long long answer=0;
	int n, k;
	std::cin>> n>> k;
	for(int i=k+1; i<=n; i++){
		int dev= n/i;
		int mod= n%i;

		answer+= dev*(i-k);
		if(mod-k>= 0){
			answer+= mod-k;
		
			if(k> 0)
				answer++;
		}
	}

	std::cout<<answer<<std::endl;

	return 0;
}