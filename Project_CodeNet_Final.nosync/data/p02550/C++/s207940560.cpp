#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define INF 2000000000
#define INF2 2000000000000000000
 
using namespace std;

int main() {
    
    IOS;

    ll n,x,m;
    cin >> n >> x >> m;
    ll arr[m + 5];
    arr[0] = x;
    map<ll, int>s;
    s[x] = 0;
    if(n <= m + 4) {
    	ll sum = x;
    	for(int i = 1; i < n; i++) {
    		arr[i] = (arr[i - 1] * arr[i - 1])%m;
    		sum += arr[i];
    	}
    	cout << sum;
    	return 0;
    }

    n--;
    ll tot = x;
    int startPos;
    int len;
    for(int i = 1; i <= m + 3; i++) {
   		arr[i] = (arr[i - 1] * arr[i - 1])%m;
   		if(s.find(arr[i]) != s.end()) {
   			startPos = s[arr[i]];
   			len = i - startPos;
   			break;
   		}
   		tot += arr[i];
   		s[arr[i]] = i;
   		n--;	
    }
    ll sum = 0;
	for(int j = startPos; j <= startPos + len - 1; j++)
   		sum += arr[j];
   	tot += (n/len) * sum;
   	n %= len;
   	for(int j = startPos; j <= startPos + n - 1; j++)
   		tot += arr[j];
   	cout << tot;

}