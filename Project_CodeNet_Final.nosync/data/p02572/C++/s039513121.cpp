#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;	cin>>N;
	vector<ll> data(N);
	ll sum=0,ans=0;
	FOR(i,0,N){
		cin>>data.at(i);
		sum+=data.at(i);
	}

	FOR(i,0,N){
		ll sumc=sum-data.at(i);
		sumc%=mod;
		ans+=(sumc*data.at(i))%mod;
		ans%=mod;
		sum-=data.at(i);
	}

	cout<<ans<<endl;




    return 0;
}

