#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
const int INF = 1000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007ll;


int main(){
	for(;;){
		int n;
		std::cin >> n;
		if(n==0){
			exit(0);
		}else{
			std::vector<int> a(n);
			rep(i,n)std::cin >> a[i];
			sort(all(a));
			std::cout << accumulate(a.begin()+1,a.end()-1,0)/(n-2) << std::endl;
		}
	}
}

