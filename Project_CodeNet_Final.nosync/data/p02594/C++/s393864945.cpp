#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff 					first
#define ss 					second
#define sz(x) 				(int)(x).size()
#define all(x) 				begin(x), end(x)
#define rall(x) 			(x).rbegin(), (x).rend() 
#define rsz 				resize
#define ins 				insert 
#define ft 					front() 
#define bk 					back()
#define pf 					push_front 
#define pb 					push_back
#define eb 					emplace_back 
#define lb 					lower_bound 
#define ub 					upper_bound 
#define pqmax				priority_queue<int>
#define pqmin				priority_queue<int,vector<int>,greater<int>>
#define transup(x)			transform(x.begin(),x.end(),x.begin(),::toupper)
#define translow(x)			transform(x.begin(),x.end(),x.begin(),::tolower)
#define rep(i,a,b) 			for (int i = (a); i < (b); ++i)
#define per(i,a,b) 			for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) 			for (auto a: x)

#define setbits(x)  		__builtin_popcountll(x)
#define zerobits(x)			__builtin_ctzll(x)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    auto start = std::chrono::high_resolution_clock::now();
    /*start from here*/
    
    int x;
    cin>>x;
    if(x>=30){
    	cout<<"Yes\n";
    }else{cout<<"No\n";}

	

	auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     

    return 0;

    /*STUFF TO LOOK:	
	1. Special cases/corner cases(n==0||n==1)
	2. Variables in loops
	3. Input ranges
	*/
}
