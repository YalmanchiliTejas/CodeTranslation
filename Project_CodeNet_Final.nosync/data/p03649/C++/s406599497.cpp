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
#include <cctype>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
const int SIZE=200001+5000;
//int arr[SIZE]={};
 
int main(){
	ll N;
	cin>>N;
	ll a[51]={};
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	ll zouka=0;
	bool flag=1;
	ll prev=0;
	while(flag){
		prev=zouka;
		flag=0;
		for(int i=0;i<N;i++){
			if(a[i]+prev>N-1){
				ll times=(a[i]+prev-(N-1)+N)/(N+1);
				a[i]-=times*(N+1);
				zouka+=times;
				flag=1;
				//cout<<times<<endl;
			}
		}
	}
	cout<<zouka<<endl;
	return 0;
}