
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
#define 	ll		    long long
#define 	rep(i,a,n)  for(int i=a;i<n;i++)
#define 	MOD 		1000000007
#define 	vp 			vector<pair<int,int> >
#define 	ff 			first
#define 	ss 			second
#define 	pb 			push_back
#define 	all(x) 		(x.begin(),x.end())
#define 	dg(x)		cerr<<"--- x = "<<x<<"\n"
#define 	endl		"\n"


using namespace std;
const int N = 1e5;
ll ar[N];

void solve(){
	int x; cin >> x;
	if(x >= 30)
		cout << "Yes";
	else
		cout << "No";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
