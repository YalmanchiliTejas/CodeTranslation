#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<vector>
#include<string>
#include<cstring>
#include<ctype.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>
	new_data_set;
//   <<implemented_sorted_vector>>  new_data_set p;
//   <<insert_like_set>>           insert(key):log(n)
//<<accessing_iterator_by_index>> find_by_order(idx):log(n)
//	    <<accessing_by_value>>   order_of_key(key):log(n)
// << replace less<int> by greater<int> for descending order>>
// find(key), erase(find(key)) works the same!
typedef long long ll;
typedef long l;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ERR(x) cout<<"#x:"<<x<<endl
#define ERR2(x,y) cout<<"#x:"<<x<<" "<<"#y:"<<y<<endl;
#define ERR3(x,y,z) cout<<"#x:"<<x<<" "<<"#y:"<<y<<" "<<"#z:"<<z<<endl;
#define show(v) for(auto e: v) cout<<e<<" ";
#define showArr(A,n) for(int i=0;i<n;i++) cout<<A[i]<<" ";
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define mp make_pair
#define endl "\n"
#define ff first
#define ss second
#define all(v) v.begin(),v.end()

ll solve(ll n, vector<ll>&A){
	vector<ll>pref(n+1,0);
	for(int i=n-1;i>=0;i--){
		pref[i] = (pref[i+1] + A[i])%MOD;
	}
	ll s = 0;
	for(int i=0;i<n-1;i++){
		s = (s+(A[i]*pref[i+1])%MOD)%MOD;
	}
	return s;
}

int main()
{
	ll n;
	cin>>n;
	vector<ll>A(n);
	FOR(i,0,n){
		cin>>A[i];
	}
	cout<<solve(n,A)<<endl;
	return 0;
}
