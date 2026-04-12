#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<cmath>
typedef long long int ll;
#define VI vector<int>

#define rep(i,a) for(int i=0;i<(a);i++)

int n,m;

using namespace std;


int main(){
	int a,b;
	cin>>a>>b;
	if(a>b){
		cout<<"a"<<" > "<<"b"<<endl;
	}else if(a<b){
		cout<<"a"<<" < "<<"b"<<endl;
	}else if(a == b){
		cout<<"a"<<" == "<<"b"<<endl;
	}
	return 0;
}