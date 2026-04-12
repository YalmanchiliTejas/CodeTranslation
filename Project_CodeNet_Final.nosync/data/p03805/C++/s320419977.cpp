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

	int n, m, a, b;
	cin>>n>>m;
	int edge[8][8];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			edge[i][j]=0;
		}
	}
	for(int i=0; i<m; i++){
		cin>>a>>b;
		edge[a-1][b-1]=1;
		edge[b-1][a-1]=1;
	}

	vector<int> data(n-1);
	for(int i=0; i<n-1; i++){
		data[i]=i+1;
	}
	long cnt=0;
	do{
		bool flag=true;
		int p=0;
    	for(unsigned int i=0; i<n-1; ++i){
    		if(!edge[p][data[i]]){
				flag=false;
				break;
			}
			p=data[i];
		}
		if(flag){
			cnt++;
		}
	}while(next_permutation(data.begin(), data.end()));

	cout<<cnt<<endl;

	return 0;
}

