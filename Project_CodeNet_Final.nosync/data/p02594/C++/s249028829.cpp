//                _                                      
//  ___ _ __ ___ (_) __ ___      ___   _ _ __ ___  _ __  
// / __| '_ ` _ \| |/ _` \ \ /\ / / | | | '_ ` _ \| '_ \ 
// \__ \ | | | | | | (_| |\ V  V /| |_| | | | | | | |_) |
// |___/_| |_| |_|_|\__, | \_/\_/  \__,_|_| |_| |_| .__/ 
//                  |___/                         |_|  
//code by smigwump
//https://codeforces.com/blog/entry/62393 hashing hack protection
//https://codeforces.com/blog/entry/61587 rand() alternatives
//https://codeforces.com/blog/entry/61675 randomized hack protection
#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define PER(i,a,b) for(ll i = a; i >= b; i--)

using namespace std;

int main() {
	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
	// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n>=30) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }
	return 0;
}