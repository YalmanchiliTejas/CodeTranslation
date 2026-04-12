#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//const int MAX=;
 
 
 
int main(){
	int N;
	cin>>N;
	int H[21];
	rep1(i,N)cin>>H[i];
	
	int ans=1;
	for(int i=2;i<=N;i++){
		bool ok=true;
		rep1(j,i-1)if(H[j]>H[i])ok=false;
		if(ok)ans++;
	}
	cout<<ans<<endl;
}