#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<cmath>
#include<ctime>
#include<complex>

using namespace std;

#define REP(i,s,e) for(int i=int(s);i<=int(e);i++)
#define rep(i,n) for(int i=0;i<int(n);i++)


void f(vector<int>& v){

v.push_back(v.front());
v.erase(v.begin());

}

void g(vector<int>& v){

v.insert(v.begin(),v.back());
v.pop_back();

}

int main(){

	while(true){

	vector<int>NS(4); NS[0]=1; NS[1]=5; NS[2]=6; NS[3]=2;
	vector<int>EW(4); EW[0]=1; EW[1]=3; EW[2]=6; EW[3]=4;
	vector<int>D(4);  D[0]=5;  D[1]=3;  D[2]=2;  D[3]=4;

	int n; string a;

	cin >> n;
	if(n==0) break;

    int c=1;
	rep(i,n){

	cin >> a;

	if(a=="North"){

		g(NS);
		c+=NS[0];
		EW[0]=NS[0]; EW[2]=NS[2];
		D[0]=NS[1];  D[2]=NS[3];
	}

	if(a=="East"){

		g(EW);
		c+=EW[0];
		NS[0]=EW[0]; NS[2]=EW[2];
		D[1]=EW[1];  D[3]=EW[3];
	}

	if(a=="South"){

		f(NS);
		c+=NS[0];
		EW[0]=NS[0]; EW[2]=NS[2];
		D[0]=NS[1];  D[2]=NS[3];
	}

	if(a=="West"){

		f(EW);
		c+=EW[0];
		NS[0]=EW[0]; NS[2]=EW[2];
		D[1]=EW[1];  D[3]=EW[3];
	}

	if(a=="Right"){

		g(D);
		c+=NS[0];
		NS[1]=D[0]; NS[3]=D[2];
		EW[1]=D[1]; EW[3]=D[3];
	}

	if(a=="Left"){

		f(D);
		c+=NS[0];
		NS[1]=D[0]; NS[3]=D[2];
		EW[1]=D[1]; EW[3]=D[3];
	}
	}

	cout << c << endl;

	}

	return 0;
}