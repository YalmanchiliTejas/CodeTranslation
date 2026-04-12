#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a,b,c,x,y;cin>>a>>b>>c>>x>>y;

	if(a+b > c*2){
		int mi = min(x,y);
		if(x==y)cout<< c*2*mi<<endl;

		x -=mi; y-=mi;
		if(x){
			if(a >= c*2){
				cout<<c*2*mi+c*2*x<<endl;
			}else {
				cout<<c*2*mi+a*x<<endl;
			}
		}
		if(y){
			if(b >= c*2){
				cout<<c*2*mi+c*2*y<<endl;
			}else {
				cout<<c*2*mi+b*y<<endl;
			}
		}


	}else {
		cout<<a*x+b*y<<endl;
	}
}


