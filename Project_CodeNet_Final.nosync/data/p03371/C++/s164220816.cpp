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
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int cost1 =x*a+y*b;
	int cost2=min(x,y)*2*c;
	if(x>y){
		cost2+=a*(x-y);
	}
	else{
		cost2+=b*(y-x);
	}
	int cost3=max(x,y)*2*c;
	cout<<min(cost1,min(cost2,cost3))<<endl;
}