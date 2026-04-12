#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define frfr  freopen("input.text","r",stdin); //freopen("output.txt","w",stdout)
#define LL long long int
#define wh int T;cin >> T;while(T--)
#define foro(i,n) for(int i=0;i<n;i++)
#define forn(i,k,n) for(int i=k;i<n;i++)
#define PB push_back
#define mod 1000000007 
#define UMP unordered_map<int,int>
int main()
{
	LL n;
	cin >> n;
	LL arr[n];
	foro(i,n){
	 cin >> arr[i];
	}
	LL sum = 0;
	LL totalsum = 0;
	foro(i,n){
		totalsum = (totalsum + arr[i]);
	}
	foro(i,n){
		totalsum = totalsum - arr[i];
		sum = (sum + ((totalsum%mod)*(arr[i]%mod))%mod)%mod;
	}
	cout << sum << endl;
		
	
}
