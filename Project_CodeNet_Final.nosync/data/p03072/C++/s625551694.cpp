#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<cmath>
#include<complex>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main(void)
{
  int n;
	int h[22];
	int ans = 1;
	bool p = false;

  cin >> n;
	rep(i,n) cin >> h[i];
	for(int i = n-1;i>0;i--){
		rep(j,i){
			if(h[i]<h[j]){
				p = false;
				break;
			}else{
				p = true;
			}
		}
		if(p) ans++;
	}

	cout << ans << endl;
  return 0;
}
