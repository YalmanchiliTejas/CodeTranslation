#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

LL a[50];
int main() {
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N,greater<LL>());
	LL ret=0;
	while(1){
		int k=1;
		for(;k<N;k++){
			if(a[0]-a[k]>=N){
				break;
			}
		}
		if(k==N){
			break;
		}
		LL p=(a[0]-a[k]-N)/(1+N);
		ret+=p*k;
		for(int i=0;i<k;i++){
			a[i]-=p*(N-(k-1));
		}
		for(int i=k;i<N;i++){
			a[i]+=p*k;
		}
		while(a[0]-a[k]>=N){
			ret++;
			a[0]-=N;
			for(int i=1;i<N;i++){
				a[i]++;
				if(a[i-1]<a[i]){
					swap(a[i-1],a[i]);
				}
			}
		}
	}
	if(a[0]>=2*N){
		LL d=a[0]-2*N;
		ret+=N*d;
		for(int i=0;i<N;i++){
			a[i]-=d;
		}
	}
	while(a[0]>=N){
		ret++;
		a[0]-=N;
		for(int i=1;i<N;i++){
			a[i]++;
			if(a[i-1]<a[i]){
				swap(a[i-1],a[i]);
			}
		}
	}
	cout << ret << endl;


	return 0;
}

