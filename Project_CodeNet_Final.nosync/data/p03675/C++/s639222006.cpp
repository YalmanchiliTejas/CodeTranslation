#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int n;
	cin>>n;
	vector<int> one,two;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(i%2){
			one.push_back(a);
		}
		else{
			two.push_back(a);
		}
	}
	vector<int> temp;
	if(n%2==0){
		temp=two;
		two=one;
		one=temp;
	}
	if(n==1){
		cout<<two[0]<<endl;
		return 0;
	}
	if(two.size()>0){
		for(int i=two.size()-1;i>=0;i--){
			cout<<two[i]<<" ";
		}
	}
	if(one.size()>0){
		for(int i=0;i<one.size()-1;i++){
			cout<<one[i]<<" ";
		}
		cout<<one[one.size()-1]<<endl;
	}
	return 0;
}