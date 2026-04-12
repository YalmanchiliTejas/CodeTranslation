#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(c,itr) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define INF 1e9;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	x=x-z;
	int ans=x/(y+z);
	cout<<ans;
	return 0;
}