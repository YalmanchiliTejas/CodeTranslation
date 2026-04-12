#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf=1e9;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
	int n,m;
	cin>>n>>m;

	if(n==m)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
