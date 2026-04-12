#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;

int main()
{
	int MOD = pow(10, 9)+7;
	int N; cin >> N;
	vector<ll> data(N);
	for (int i = 0; i < N; i++)cin >> data[i];
	ll sum=0;
	ll ans=0;
	for (int i = 0; i < N; i++)sum += data[i];
	sum %= MOD;
	ll temp;
	for (int i = 0; i < N; i++) {
		sum -= data[i];
		if (sum < 0)sum += MOD;
		ans += sum * data[i];
		ans %= MOD;
	}
	cout << ans<<endl;
}