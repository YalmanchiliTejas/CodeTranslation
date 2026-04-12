//----------ACCIDENTAL COMPETITIVE PROGRAMMER---------------------

#include<bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
using namespace std;

#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair


const LL MOD = ((1e9) + 7) ;
const LD EPS = 0.0000001 ;

int D;
int SZ;
vector<int> arr;
LL cache[10000 + 1][101][2];
//bool done[10000 + 1][101][2];
LL pows(LL a, LL b)
{
	if (b == 0)
		return 1;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2)
		temp = (temp * a) % MOD;
	return temp;
}

LL solve(int idx, int rem, int can){
	if (idx == SZ){
		return rem == 0;
	}
//	cout << idx << " " << rem << " " << can << endl;
	LL &ans = cache[idx][rem][can];
	if (ans != -1)
		return ans;
	ans = 0;
	if (can){
		for (int i = 0; i <= 9; i++){
			ans = (ans + solve(idx + 1, (rem + i) % D, can) ) % MOD;
		}
	} else {
		for (int i = 0; i < arr[idx]; i++){
			ans = (ans + solve(idx + 1, (rem + i) % D, 1) ) % MOD;
		}
		ans = (ans + solve(idx + 1, (rem + arr[idx]) % D, 0)) % MOD;
	}
//	cout << idx << " " << rem << " " << can << " " << ans << endl;
	return ans;
}

LL compute(string s)
{
	for (int i = 0; i < s.size(); i++){
		arr.PB(s[i] - '0');
	}
//	reverse(arr.begin(), arr.end());
	SZ = arr.size();
    memset(cache, -1, sizeof(cache));
	return (solve(0, 0, 0) - 1 + MOD) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    cin >> D;
   // cout << ((MOD + 2) * (MOD + 3)) % MOD << endl;
    cout << compute(s) << endl;


	return 0;
}