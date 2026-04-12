/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Code author: Saurabh Singhal
Code copy karne vaale tera muh kaala
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ppb pop_back

using namespace std;
typedef long long int ll;
typedef vector<int> vi_t;
typedef vector<ll> vll_t;
int t=1;
vll_t a,b;
int  main(){
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
	// #endif
	int n;
	cin>>n;
	int a;
	cin>>a;
	int count=1,ma=a;
	for(int i=1;i<n;i++){
		int b;
		cin>>b;
		ma=max(ma,b);
		if(b==ma){
			count++;
		}
	}
	cout<<count<<endl;
}