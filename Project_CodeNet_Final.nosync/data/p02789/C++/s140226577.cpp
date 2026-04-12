/*

Auther: Ganesh Bhandarkar
							#   RUN   #
		<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include<bits/stdc++.h>
using namespace std;

/* KEYWORDS */
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define sq(a) (a)*(a)
#define rep(i,a,b) for(int i=a;i<b;++i)

/*DATATYPES */
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef pair<int , int > pi;
typedef pair<int , char > pic;
typedef pair<char , char > pc;
typedef pair<char , int > pci;

/*Constants */
const ll mod = 10000000007;

/* Booleans */
// bool OE(int n)  if(n & 1){ return true; } else false;


int main(){

	// #ifndef OJ
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	
	
	FASTIO

	int n,m;
	cin>>n>>m;
	if(n>m){
		cout<<"No";
	}else if(n==m){
		cout<<"Yes";
	}


	return 0;
}