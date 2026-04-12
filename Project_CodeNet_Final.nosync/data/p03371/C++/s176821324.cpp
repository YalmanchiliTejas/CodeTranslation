#include<bits/stdc++.h>
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c,x,y;
	vi v;
	cin >> a >> b >> c >> x >> y;
	
	int d =  (x * a) + (y * b);
	
	int cu ; 
	if(x > y){
		int w = 2 * y;
		int jum = w * c;
		int se = x - y;
		int jum2 = se * a;
		int tot = jum + jum2 ;
		
		
		int t = 2 * x;
		int jums = c * t;
		
		cu = min(tot,jums);
		
	}else if(x < y){
		int w = 2 * x;
		int jum = w * c;
		int se =  y - x;
		int jum2 = se * b;
		int tot = jum + jum2 ;
		
		int t = 2 * y;
		int jums = c* t;
		
		cu = min(tot,jums);
		
	}else{
		
		int w = 2 * x;
		int jum = w * c;
		
		cu = jum ;
	}
	cout << min(d,cu) << endl;
	
	
	return 0;
}
