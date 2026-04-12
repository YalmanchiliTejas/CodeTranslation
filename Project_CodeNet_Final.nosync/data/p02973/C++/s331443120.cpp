
/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define dbg(x) cerr << #x << " = " << x << endl
#define endl "\n"
#define int long long int
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)

//const int INF=1e9+5;//billion
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
string alpha = "abcdefghijklmnopqrstuvwxyz";
/*----------JU IS LOVE----------*/
//int power(int a,int b,int m){int ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
//int power(int a, int b){int ans=1;while(b){if(b&1)ans=ans*a;b/=2;a=a*a;}return ans;}

// int LIS(int arr[], int n) {

// 	if (n == 0) return 0;
// 	set<int> s;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		/* code */
// 		auto ret = s.insert(arr[i]);
// 		set<int>::iterator it;

// 		if (ret.second)
// 			it = ret.first;

// 		it++;

// 		if (it == s.end())
// 			continue;
// 		else
// 			s.erase(it);

// 	}

// 	return s.size();


// }

int LIS(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

signed main() {
 
	crap;


	int n;
	cin >> n;

	int arr[n];
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> arr[i];

		arr[i] = -arr[i];
		v.push_back(arr[i]);
	}

	cout << LIS(v) << endl;

	return 0;
}




