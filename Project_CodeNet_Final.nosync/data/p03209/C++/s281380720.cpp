#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> p_int;
typedef pair<ll,ll> p_ll;
typedef tuple<ll,ll,ll> t3_ll;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
p_ll pbcnt[51];
ll pbp[51];
vector<ll> pcnt[51];
ll ansp = 0;
bool fin = false;

void search(ll now,ll rem) {
	if (!fin) {
		if (now == 0) {
			ansp += 1;
			fin = true;
		} else {
			if (rem == 1) {
				fin = true;
			} else if (rem < 1 + pbcnt[now-1].first + pbcnt[now-1].second + 1) {
				search(now-1,rem-1);
				// cout << "colled" << endl;
			} else if (rem == 1 + pbcnt[now-1].first + pbcnt[now-1].second + 1) {
				ansp = ansp + pbp[now-1] + 1;
				fin = true;
			} else if (rem != pbcnt[now].first + pbcnt[now].second) {
				ansp = ansp + pbp[now-1] + 1;
				search(now-1,rem-2-(pbcnt[now-1].first + pbcnt[now-1].second));
				// cout << "colleded" << endl;
			} else {
				ansp = ansp + pbp[now-1] * 2 + 1;
				fin = true;
			}
		}
	}
}

int main() {
	pbcnt[0].first = 1;pbcnt[0].second = 0;pbp[0] = 1;
	for (int i = 1;i < 51;i++) {
		pbcnt[i].first = pbcnt[i-1].first * 2 + 1;
		pbcnt[i].second = pbcnt[i-1].second * 2 + 2;
		pbp[i] = pbcnt[i].first;
	}
	ll n,x;
	cin >> n >> x;
	search(n,x);
	cout << ansp << endl;
}