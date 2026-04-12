#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <bitset>
using namespace std;
#define INF	100000000
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define SS stringstream
#define rep(i,n) for(int i = 0; i < n; i++)
#define sz(x) ((int)(x).size())
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).begin(), (x).end(), greater<int>() )
#define clr(a,b) memset((a),(b),sizeof(a))
typedef pair<int, int> P;
typedef long long int ll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<P> Vp;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

Vp vec;
int ans[101];
int rank = 1;

int main(){
	while(true){
		int temp1, temp2; char trash; scanf("%d%c%d", &temp1, &trash, &temp2);
		if(temp1 == 0 && temp2 == 0) break;
		vec.pb(P(temp2,temp1));
	}
	sort(vec.begin(), vec.end(), greater<P>());
	ans[vec[0].sec] = rank;
	for(int i = 1; i < vec.size(); i++){
		if(vec[i].fi == vec[i-1].fi) ans[vec[i].sec] = rank;
		else{
			rank++;
			ans[vec[i].sec] = rank;
		}
	}
	int temp;
	while(cin >> temp){
		cout << ans[temp] << endl;
	}
}