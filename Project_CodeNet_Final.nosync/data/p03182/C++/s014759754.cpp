#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<random>
#include<stdio.h>
using namespace std;



static const int MAX_SIZE = 1 << 18; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

typedef long long Int;
Int segMin[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

//区間[a, b)に値xを加算する.
void add(int a, int b, Int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return; //もし交差しない区間であれば終える.
	
	if (a <= l && r <= b){ //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
		segAdd[k] += x;  //区間[l, r)にkを加算する.
		return;
	}
	
	add(a, b, x, k * 2 + 1, l, (l + r) / 2); //子の区間に(必要があれば)xを加算する.
	add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃

	//親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である.一様に加算される値は更新しなくて良い.
	segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

Int getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return 1e20-1;
	
	if (a <= l && r <= b) return (segMin[k] + segAdd[k]); //完全に内包されていれば,その区間の最小値を返す.
	
	Int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
	Int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める
	
	return (min(left, right) + segAdd[k]); //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である (大切なので2回書きました!!)
	
}
typedef long long int ll;
int main(){
    ll N,M;cin>>N>>M;
    vector<vector<pair<ll,ll>>> interval(N,vector<pair<ll,ll>>(0));
    for (int i=0;i<M;i++){
        ll l,r,a;
        cin>>l>>r>>a;
      	pair<ll,ll> p;
      	p.first=r-1;
        p.second=a;
        interval[l-1].push_back(p);
    }

	ll ans=0;
    for (int i=N-1;i>-1;i--){
        for (int j=0;j<interval[i].size();j++){
            ll r,a;
          	r=interval[i][j].first;
            a=interval[i][j].second;
            add(i,r+1,-a);
        }
      	ll zero=0;
        ll ans=std::max(zero,-getMin(0,N));
        if (i>0){
            add(i-1,i,-ans);
        }
      	else{
          cout<<ans<<endl;
        }
    }
}