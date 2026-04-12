#include<bits/stdc++.h>

#define FOR(i, a, b) for(int(i)=(a);(i)<(b);(i)++)
#define REP(i, n) FOR((i), 0, (n))

#define RFOR(i, b, a) for(int(i)=(b); (i)>=(a); (i)--)
#define RREP(i, n) FOR((i), (n), 0)

#define pb push_back
#define mp make_pair 

using namespace std;

const int INF=INT_MAX/4;
const int MOD=1000000007;
const double EPS=1e-14;

const bool debug_flag=true;

void debug(string str){
	if(debug_flag){
		cout<<str<<endl;
	}
}

void debugs(string str){
	if(debug_flag){
		cout<<str;
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.precision(10);

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int k=n-1;
	while(k>=0){
		cout<<a[k]<<" ";
		k-=2;
	}
	if(n%2==0){
		k=0;
	}else{
		k=1;
	}
	if(n>1){
	while(k<n-2){
		cout<<a[k]<<" ";
		k+=2;
	}
	cout<<a[k];
	}
	cout<<endl;

	return 0;
}

