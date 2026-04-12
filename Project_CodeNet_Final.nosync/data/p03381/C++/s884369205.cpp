#include <iostream>
#include <vector>
#include <algorithm>

# define REP(i,n) for(int i=0; i<n; i++)

using namespace std;


int main(){
	
	int n;
	long long int input, median1, median2;
	vector<long long int> x, sorted;
	
	scanf("%d", &n);
	REP(i,n){
		scanf("%lld", &input);
		x.push_back(input);
		sorted.push_back(input);
	}
	
	sort(sorted.begin(), sorted.end() );
	
	median1 = sorted[n/2-1];
	median2 = sorted[n/2];
	
	REP(i,n){
		if (x[i]<=median1) printf("%lld\n", median2);
		else printf("%lld\n", median1);
	}
	
	return 0;
	
}
