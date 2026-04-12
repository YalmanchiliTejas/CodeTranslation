#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <array>

using namespace std;

vector<long long> v;
vector<long long> calc;

int main(){
	int n;cin>>n;
	v.resize(n);
	calc.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) calc[i] = v[i] + v[n-i-1];

	long long ans = 0;

	for(int i=1;i<n;i++){
		long long tmp = 0;
		for(int j=i;j<n;j+=i){
			if((n-j-1) <= i) break;
			if(j >= n-j-1){
				if(((n-j-1)%i) == 0) break;
			}
			tmp += calc[j];
			ans = max(ans,tmp);
		}
	}
	cout<<ans<<endl;
	return 0;

}