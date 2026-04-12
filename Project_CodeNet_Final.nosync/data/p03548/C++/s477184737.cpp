#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<bitset>
#include<cctype>
#include<iomanip>
using namespace std;
const int N = 100;
typedef long long ll;
#define PI 3.1415927

int main(){
	int x,y,z,i=0;
	while(cin>>x>>y>>z)
	{
		i=0;
		x=x-z;
		while(x>=0){
			x=x-z-y;
			i++;
			}
		cout<<i-1<<endl;
		
		
		}
	return 0;
}