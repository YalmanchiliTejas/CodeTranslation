//標準関数をすべてインクルードする。
#include <bits/stdc++.h>
using namespace std;

int main(){
    //cin coutを高速化
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

    int n, m;

    cin >> n >> m;

    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}