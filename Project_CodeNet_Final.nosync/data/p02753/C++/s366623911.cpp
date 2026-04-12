#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll  long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define br cout <<"\n";
#define all(x)  (x).begin(),(x).end()
#define rall(x)  (x).rbegin(),(x).rend()
#define tr(c,i) for(auto i : c)
#define pii pair< int,int >
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define pq priority_queue< pair<ll,pii> ,vector<pair<ll,pii>>,greater <pair<ll,pii>> >p;//container adapter makes ascending q
#define er(x) cout << x << " "
#define err(x,y) cout << x << " "<<y
using namespace std;
const int dx[] = { 1, -1 , 0 , 0  };
const int dy [] = { 0 ,0 , 1 , -1  };
const int MOD = 1000 * 1000 * 1000 + 7 ;
const int N = 1000+5 ;
const int INF = INT_MAX ;
const int M = 200005;
char a[N][N]; 
int main ( ){
fast_io();
string s ;
cin >> s ;
map<int , int >mp ; 
for(char &x : s )
mp[x]++ ;
cout << ( mp.size() == 1 ? "No":"Yes") ,br 	
 
return 0 ;
 
}
