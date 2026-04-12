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
typedef pair<LL,LL> P;

const int L=1e5+1;
vector<int> es[L];
LL N;

bool ok;
int f(int r,int p)
{
	int c=0;
	int sum=1;
	for(int i=0;i<es[r].size();i++){
		int j=es[r][i];
		if(j==p){
			continue;
		}
		int v=f(j,r);
		if(v%2){
			c++;
		}
		sum+=v;
	}
	if((N-sum)%2){
		c++;
	}
	if(c==0||c>=2){
		ok=true;
	}
	return sum;
}

int main(){
    scanf("%lld",&N);
    for(int i = 0 ; i < N-1 ; i++){
		LL a;
		LL b;
        scanf("%lld",&a);
        scanf("%lld",&b);
		es[a].push_back(b);
		es[b].push_back(a);
    }

	f(1,0);
	if(ok){
		cout << "First" << endl;
	}
	else{
		cout << "Second" << endl;
	}


    return 0;
}
