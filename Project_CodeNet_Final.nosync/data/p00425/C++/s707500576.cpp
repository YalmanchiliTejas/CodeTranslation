#define	_USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <set>
#include <complex>
#include <utility>
#include <numeric>
#include <bitset>
using namespace std;
const int INF=1<<30;

typedef pair<int,int> P;
int dice[6]={1,5,3,2,4,6};

int rot(string s){
	
	int a[6]={0};
	if(s=="North"){
		a[0]=dice[3];
		a[1]=dice[0];
		a[2]=dice[2];
		a[3]=dice[5];
		a[4]=dice[4];
		a[5]=dice[1];
	}
	else if(s=="East"){
		a[0]=dice[4];
		a[1]=dice[1];
		a[2]=dice[0];
		a[3]=dice[3];
		a[4]=dice[5];
		a[5]=dice[2];
	}
	else if(s=="West"){
		a[0]=dice[2];
		a[1]=dice[1];
		a[2]=dice[5];
		a[3]=dice[3];
		a[4]=dice[0];
		a[5]=dice[4];
	}
	else if(s=="South"){
		a[0]=dice[1];
		a[1]=dice[5];
		a[2]=dice[2];
		a[3]=dice[0];
		a[4]=dice[4];
		a[5]=dice[3];
	}
	else if(s=="Right"){
		a[0]=dice[0];
		a[1]=dice[4];
		a[2]=dice[1];
		a[3]=dice[2];
		a[4]=dice[3];
		a[5]=dice[5];
	}
	else{
		a[0]=dice[0];
		a[1]=dice[2];
		a[2]=dice[3];
		a[3]=dice[4];
		a[4]=dice[1];
		a[5]=dice[5];
	}
	
	for(int i=0;i<6;i++)
		dice[i]=a[i];
	return dice[0];
}

int main(){
	
	int n;
	string s;
	
	while(cin>>n&&n){
		long long ans=1;
		for(int i=0;i<n;i++){
			cin>>s;
			ans+=rot(s);
		}
		cout<<ans<<endl;
		dice[0]=1;
		dice[1]=5;
		dice[2]=3;
		dice[3]=2;
		dice[4]=4;
		dice[5]=6;
	}

}