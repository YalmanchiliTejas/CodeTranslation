#include <iostream>
#include <bits/stdc++.h>  

#define int long long int
#define ull unsigned long long int
#define for0(i, n) for (int i = 0; i < (int)(n); i++) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); i++) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); i++) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; i--) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; i--) // reverse 1 based


#define pb push_back
#define fi first
#define se second

#define I_max (int)1e9+7
#define size6 (int)1e6


#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin, (x).rend() 
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef double ld;

//-----------------------------------------------------------------------------------END-------------------------------------------------------------------------------------//

int a[size6];


bool inc(vi vec){
	for1(i,vec.size()-1){
		if(vec[i]<vec[i-1])return 0;
	}
	return 1;
}


void solve(){
   int n;cin>>n;
   for0(i,n)cin>>a[i];

   int total=0;
   for0(i,n){
	   total+=a[i];
	   total%=I_max;
   }

   int temp=0,ans=0;
   for0(i,n){
	   temp+=a[i];
	   if(total-temp<0)total+=I_max;
	   ans+= a[i]*(total-temp);
	   ans%=I_max;
   }
   cout<< ans <<'\n';
}



int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout.precision(10);
	//cout << fixed;
	//int tt;cin>>tt;
	//while(tt--){
		solve();
	//}
	return 0;
}


