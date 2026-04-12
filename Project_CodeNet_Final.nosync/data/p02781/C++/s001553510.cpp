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


LL f(string N,int K){
	LL s=N.size();
	if(K==0){
		return 1;
	}
	if(s==0){
		return 0;
	}
	LL ret=0;
	for(int i=0;i<=N[0]-'0';i++){
		if(i==N[0]-'0'){
			if(i==0){
				ret+=f(N.substr(1),K);
			}
			else{
				ret+=f(N.substr(1),K-1);
			}
		}
		else if(i==0){
			if(K==1){
				ret+=9*(s-1);
			}
			else if(K==2){
				ret+=9*9*(s-1)*(s-2)/2;
			}
			else{
				ret+=9*9*9*(s-1)*(s-2)*(s-3)/6;
			}
		}
		else if(K==1){
			ret+=1;
		}
		else if(K==2){
			ret+=9*(s-1);
		}
		else{
			ret+=9*9*(s-1)*(s-2)/2;
		}
	}
	return ret;
}


int main(){
	string N;
	int K;
	cin >> N >> K;
	cout << f(N,K) << endl;

    return 0;
}
