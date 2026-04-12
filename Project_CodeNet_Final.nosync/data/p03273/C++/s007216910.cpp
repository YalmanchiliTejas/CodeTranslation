#include <bits/stdc++.h>
using namespace std;

#define FOR(i, s, e)   for(int i = (s); i < (e); i++)
#define FOR64(i, s, e) for(ll  i = (s); i < (e); i++)
#define ALL(x)         (x).begin(), (x).end()
#define SORT(b, e)     sort((b), (e))
#define REV(b, e)      reverse((b), (e))
#define VSORT(v)       sort((v).begin(), (v).end())
#define VREV(v)        reverse((v).begin(), (v).end())
#define pb(a)          push_back(a)
#define INF            999999999

typedef long long ll;

#define W 0
#define B 1

int main()
{
	int h, w;
	cin >> h >> w;

	vector<int> a(h * w);

	vector<int> sum_horz(h, 0);

	int k = 0;
	FOR(j, 0, h){
		FOR(i, 0, w){
			char c;
			cin >> c;
			a[k] = (c == '.') ? W : B;
			sum_horz[j] += a[k];
			k++;
		}
	}

	vector<int> sum_vert(w, 0);

	FOR(i, 0, w){
		FOR(j, 0, h){
			sum_vert[i] += a[j * w + i];
		}
	}

	FOR(j, 0, h){
		if(sum_horz[j] == 0)
			continue;

		FOR(i, 0, w){
			if(sum_vert[i] == 0)
				continue;

			cout << ((a[j * w + i] == W) ? '.' : '#');
		}

		cout << endl;
	}

	return 0;
}

