#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int arr[20];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    
    int maxV=0;
    int ans=0;
    for(int i=0; i<n; ++i){
        if(arr[i]>=maxV){
            maxV = arr[i];
            ans++;
        }
    }
    cout << ans << endl;
	int c; cin >> c;
	return 0;

}