/* Author : Harshit Jain a.k.a. iharshit009 */
#include <bits/stdc++.h>
#define vi               vector<int>
#define pb(x)            push_back(x)
#define all(x)           x.begin(), x.end()
#define sortall(x)       sort(all(x))
#define sortrev(x)       sort(all(x), greater<int>())
#define debug(x)         cout << '>' << #x << ':' << x << endl;
#define int              long long
#define ld               long double
#define endl 			 "\n";
#define mp 				 make_pair
#define pii 			 <int, int>
#define lb 				 lower_bound
#define ub				 upper_bound
#define len(a)           int((a).size())
#define prec(n)          fixed<<setprecision(n)
#define cnt(n)           __builtin_popcountll(n)
#define pi               pair<int, int>
const int mod = 1000000007;
using namespace std;
using namespace std::chrono;
// const int N = 1e5 + 5; 
// int n;
// int a[N];



int32_t main(){
auto start = high_resolution_clock::now(); // starting clock
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t;
t = 1;
// cin >>t;
while(t--){

int n;
cin >> n;
if(n >= 30){
	cout << "Yes" << endl;
}

else{
	cout << "No" << endl;
}







}
auto stop = high_resolution_clock::now(); // stop clock
auto duration = duration_cast<microseconds>(stop - start);  // printing duration
cerr << "Time taken by function: " << duration.count() << " milliseconds" << endl; 
return 0;
}