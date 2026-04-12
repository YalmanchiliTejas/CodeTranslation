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
#define MOD 1000000007
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
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<P> Vp;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

int n,m,ans;
string str;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(true){
		ans = 1;
		int eye[6] = {1,5,3,2,4,6},teye[6];
		cin >> n;
		if(n == 0) break;
		rep(i,n){
			rep(j,6) teye[j] = eye[j];
			cin >> str;
			if(str == "North"){
				eye[0] = teye[3];
				eye[1] = teye[0];
				eye[3] = teye[5];
				eye[5] = teye[1];
			} else if(str == "East"){
				eye[0] = teye[4];
				eye[2] = teye[0];
				eye[4] = teye[5];
				eye[5] = teye[2];
			} else if(str == "West"){
				eye[0] = teye[2];
				eye[2] = teye[5];
				eye[4] = teye[0];
				eye[5] = teye[4];
			} else if(str == "South"){
				eye[0] = teye[1];
				eye[1] = teye[5];
				eye[3] = teye[0];
				eye[5] = teye[3];
			} else if(str == "Right"){
				eye[1] = teye[4];
				eye[2] = teye[1];
				eye[3] = teye[2];
				eye[4] = teye[3];
			} else{
				eye[1] = teye[2];
				eye[2] = teye[3];
				eye[3] = teye[4];
				eye[4] = teye[1];
			}
			ans += eye[0];
		}
		cout << ans << endl;
	}
}