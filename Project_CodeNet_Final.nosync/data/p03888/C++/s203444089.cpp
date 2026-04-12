#include <bits/stdc++.h>
using namespace std; 
const int dx[]={1,0,-1,0,1,-1,-1,1}; 
const int dy[]={0,1,0,-1,1,1,-1,-1}; 
const int INF = 1e9; 
const long long LINF = 1e18; 
const double EPS = 1e-8; 
#define pb push_back
#define mk make_pair 
#define fr first 
#define sc second 
#define ll long long 
#define reps(i,j,k) for(int i = (j); i < (k); ++i) 
#define rep(i,j) reps(i,0,j) 
#define all(a) (a).begin(),(a).end() 
#define MOD 1000000007 
typedef pair<int,int> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;

int main(){

	int a , b;
	cin >> a >> b;

	printf("%.8f\n",(double)(a*b)/(double)(a+b));

	return 0;
}
