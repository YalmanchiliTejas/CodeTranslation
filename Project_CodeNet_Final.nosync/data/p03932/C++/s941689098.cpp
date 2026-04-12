#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll h, w; 
ll dp[402][200][200];
bool can(pair<ll, ll> po){return (0 <= po.first && po.first < h && 0 <= po.second && po.second < w ? true : false);}
int main(){
	cin >> h >> w;
	ll a[h][w];
	for(ll i = 0; i < h; i++)for(ll j = 0; j < w; j++)cin >> a[i][j];
	dp[0][0][0] = a[0][0];
	for(ll count = 0; count < h + w - 2; count++){
		for(ll i = 0; i < h; i++){
			for(ll j = 0; j < h; j++){
				auto po = pair<ll, ll>(i, count - i), yo = pair<ll, ll>(j, count - j);
				if(!can(po) || !can(yo)) continue;
				ll dh[] = {1, 0}, dw[] = {0, 1};
				for(ll p = 0; p < 2; p++){
					for(ll y = 0; y < 2; y++){
						auto nextpo = po, nextyo = yo;
						nextpo.first += dh[p];
						nextpo.second += dw[p];
						nextyo.first += dh[y];
						nextyo.second += dw[y];
						if(!can(nextpo) || !can(nextyo)) continue;
						dp[count + 1][nextpo.first][nextyo.first] = max(dp[count + 1][nextpo.first][nextyo.first], dp[count][po.first][yo.first] + a[nextpo.first][nextpo.second] + a[nextyo.first][nextyo.second] - (nextpo == nextyo ? a[nextpo.first][nextpo.second] : 0));
					}
				}
			}
		}
	}
	cout << dp[h + w - 2][h - 1][h - 1] << endl;
	return 0;
}