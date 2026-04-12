#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define watch(x) cout << "["<<(#x) << " is " << (x) << "]" << endl

double choose(double n, double r){
	double top,second,third;
	if(r==0){
		return 1.0;
	}
	else{
		 top = 1.0;
		for(double x = 1; x <= n; ++x){
			top *= x;
		}
		 second= 1.0;
		for(double x = 1; x <= r; ++x){
			second *= x;
		}
		 third=1.0;
		for(double x = 1; x <= (n-r); ++x){
			third *= x;
		}
	}
	return (top/((second*third)));
}


void solve(){
	int x;
	cin >> x;
	if(x>=30){
		cout <<"Yes" <<endl;
	}
	else{
		cout << "No" << endl;
	}
}

int main(){
	// cout << choose(15,4) << endl;
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;

}