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
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;


void solve(long long N, std::vector<long long> s){
	LL ret=0;
	for(int i=1;i<N;i++){
		int x=0;
		int y=N-1;
		LL sum=0;
		while(x+i<N){
			if(x+i==y){
				break;
			}
			x+=i;
			y-=i;
			if(x==y){
				break;
			}
			if(y<i){
				break;
			}
			sum+=s[x]+s[y];
			ret=max(ret,sum);
		}
	}
	cout << ret << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> s(N-1-0+1);
    for(int i = 0 ; i < N-1-0+1 ; i++){
        scanf("%lld",&s[i]);
    }
    solve(N, std::move(s));
    return 0;
}
