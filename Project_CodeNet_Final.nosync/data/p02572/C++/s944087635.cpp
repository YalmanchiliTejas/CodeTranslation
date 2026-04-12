#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int fastPower(int a ,int b){
	if(b== 0)
		return 1;
	int res = fastPower(a, b/ 2);
	if(b% 2== 1)
		return ((res* res)% mod* a)% mod;
	return (res* res)% mod;
}

int findProductSum(vector<int> &A, int n)
{
    // calculating array sum (a1 + a2  ... + an)
    int array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = (array_sum + A[i])% mod;

    // calcualting square of array sum
    // (a1 + a2 + ... + an)^2
    int array_sum_square = (array_sum * array_sum)% mod;

    // calcualting a1^2 + a2^2 + ... + an^2
    int individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum = (individual_square_sum + (A[i]*A[i])% mod)% mod;

    // required sum is (array_sum_square -
    // individual_square_sum) / 2
    int ans= (array_sum_square - individual_square_sum+ mod)% mod;
    int two= fastPower(2, mod- 2);
    return (ans* two)% mod;
}

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i: v) cin >> i;
        cout << findProductSum(v, n);
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
