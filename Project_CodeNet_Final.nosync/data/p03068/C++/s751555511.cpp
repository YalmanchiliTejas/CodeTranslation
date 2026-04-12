#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N,K;
	string S;
	cin>>N>>S>>K;
	rep(i,N){
		if(S.at(i)!=S.at(K-1)){
			S.at(i)='*';
		}
	}
	cout<<S;
return 0;}

/*compile
g++ code.cpp
./a.out
run*/