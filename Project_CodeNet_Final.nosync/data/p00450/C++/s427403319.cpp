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
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main() {
while(1){
	stack<int> num;
	int last=-1;
	int n;
	cin >> n;
	if(n==0)return 0;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		int c=1;
		if(last==v){
			if(num.size()>0){
				c+=num.top();
				num.pop();
			}
		}
		else{
			if(i%2==1){
				for(int i=0;i<2;i++){
					if(num.size()>0){
						c+=num.top();
						num.pop();
					}
				}
			}
		}
		num.push(c);
		//cout << v << ": " << c << endl;
		last=v;
	}
	int ret=0;
	while(num.size()){
		if(last==0){
			ret+=num.top();
		}
		num.pop();
		last^=1;
	}
	cout << ret << endl;
}
}