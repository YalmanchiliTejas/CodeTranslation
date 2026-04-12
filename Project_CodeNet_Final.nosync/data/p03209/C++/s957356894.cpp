// Be name khoda
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAX_N = 50 + 5;
ll n, k, ans;
ll len[MAX_N];
ll tol[MAX_N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	len[0] = 1;
	tol[0] = 1;
	
  	for (int i = 1; i <= n; i++) {
    	len[i] = 2 * len[i - 1] + 1;
    	tol[i] = 2 * tol[i - 1] + 3;
    }
  
  	for (int i = n; ~i; i--) {
    	if (k <= 1)
        	break;
      	if (k < 1 + tol[i - 1]) {
        	k--;
         	continue;
        }
      	ans += len[i - 1];
      	if (k == 1 + tol[i - 1])
        	break;
      
      	ans += 1;
      	if (k == 2 + tol[i - 1])
        	break;
       	
    	if (k < 2 + 2 * tol[i - 1]) {
 	      	k -= 2 + tol[i - 1];
        	continue;
        }
      	ans += len[i - 1];
      	if (k == 2 + 2 * tol[i - 1])
        	break;
      	break;
    }

    cout << ans;
	return 0;
}