#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
const int INF = 1000000000;
const long INF64 = 1000000000000000ll;
const int MOD = 1000000007;


int main(){
	int n;
	std::cin >> n;
	int counter=0;
	rep(i,n){
		if((i+1)%15==0)counter+=600;
		else counter+=800;
	}
	std::cout <<  counter << std::endl;
}
