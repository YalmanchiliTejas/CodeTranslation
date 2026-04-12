#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<20)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

struct Data{
	string name;
	int w, l, d,sum,id;
};

int main()
{
	int n,cnt=0;
	
	while (cin >> n, n) {
		if (cnt++)cout << endl;
		vector<Data> s(n);
		for (int i = 0; i < n; i++) {
			s[i].id = i;
			cin >> s[i].name >> s[i].w >> s[i].l >> s[i].d;
			s[i].sum = s[i].w * 3 + s[i].d;
		}

		for (int i = 0; i < n-1; i++) 
			for (int j = i+1; j < n; j++) 
				if (s[i].sum < s[j].sum)swap(s[i], s[j]);
		
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (i == j)continue;
				if (s[i].sum == s[j].sum) {
					if (s[i].id > s[j].id)swap(s[i], s[j]);
				}
			}
		}

		for (int i = 0; i < n; i++)
			cout << s[i].name << ','<< s[i].sum << endl;
	}
	return 0;
}