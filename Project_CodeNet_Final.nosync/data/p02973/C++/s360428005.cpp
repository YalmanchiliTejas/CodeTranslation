#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define pm(first, second) pb(mp(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()


ll N;
vector<ll> ANS;
ll a;

//にぶたん
//右にあるもののうち一番左を求める
int searchRight(){
	int l = 0, m, r = N - 1;
	//isTrue()はbool型関数, 右側ならtrue, 左側ならfalse
	if(ANS[l] < a/*isTrue(l)*/)return l;//全部右にある
	if(ANS[r] >= a/*!istrue(r)*/)return -1;//ひとつも右にない
	while(true){
		m = (l + r) / 2;
		if(ANS[m] < a/*isTrue(m)*/){
			if(ANS[m - 1] >= a/*!isTrue(m - 1)*/){
				return m;
			}
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
}

int main(){

	cin >> N;
	ANS = vector<ll>(N, -1);

	for(ll i = 0; i < N; i ++){
		cin >> a;
		int pos = searchRight();
		ANS[pos] = a;
	}
	ll cnt = 0;
	for(ll i = 0; i < N; i ++){
		if(ANS[i] != -1)cnt ++;
		else break;
	}
	cout << cnt << endl;

	return 0;
}
