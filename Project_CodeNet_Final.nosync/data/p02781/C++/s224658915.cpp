#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;
int main()
{
	boost;
	int n, k;
	string s;
	cin >> s;
	cin >> k;
	n = s.length();
	
	int pre[n];
	pre[0] = s[0] - '0';
	for(int i = 1; i < n; i++)
	pre[i] = pre[i - 1] + (s[i] - '0');
	
	int ans = 0;
	if(k == 1) 
	ans = s[0] - '0' + 9 * (n - 1);
	else if(k == 2) {
		int i, j;
		
		int sr = s[0] - '0';
		for(int c1 = 1; c1 <= sr; c1++) {
			fo(i, 1, n) {
				int x = s[i] - '0';
				for(int c2 = 1; c2 < 10; c2++) {
					if(c1 == sr) {
						if(c2 <= x) ++ans;
						else {
							if(pre[i - 1] - pre[0] > 0)
							++ans;
						}
					}
					else ++ans;
				}
			}
		}
		--n;
		ans += ((n * (n - 1)) / 2) * 9 * 9;
	}
	else {
		int sr = s[0] - '0';
		int i, j;
		for(int c1 = 1; c1 <= sr; c1++) {
			fo(i, 1, n) {
				int x = s[i] - '0';
				fo(j, i + 1, n) {
					int y = s[j] - '0';
					
					for(int c2 = 1; c2 < 10; c2++) {
						for(int c3 = 1; c3 < 10; c3++) {
							if(c1 == sr) {
								if(c2 < x) ++ans;
								else if(c2 == x) {
									bool active = (pre[i - 1] - pre[0] > 0);
									if(active) ++ans;
									else {
										if(c3 <= y) ++ans;
										else if(pre[j - 1] - pre[i] > 0) ++ans;
									}
								}
								else if(pre[i - 1] - pre[0] > 0) ++ans;
							}
							else ++ans;
						}
					}
				}
			}
		}
		--n;
		ans += ((n * (n - 1) * (n - 2)) / 6) * 9 * 9 * 9;
	}
	cout << ans;
}
