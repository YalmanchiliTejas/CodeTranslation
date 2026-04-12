// #include <bits/stdc++.h>

// using namespace std;

// const int T = 100;

// int main() {
// 	int n, m;
// 	cin >> n >> m;
	
// 	int sum = 0;
// 	vector<int> t(n), count(T + 1, 0);
// 	for (int i = 0; i < n; i++) {
// 		cin >> t[i];
// 	}
	
// 	for (int i = 0; i < n; i++) {
// 		int d = sum + t[i] - m, k = 0;
//         cout<<d<<" "<<sum<<"    ";
// 		if (d > 0) {
// 		    for (int j = T; j > 0; j--) {
// 				int x = j * count[j];
// 				if (d <= x) {
// 					k += (d + j - 1) / j;
// 					break;
// 				}
// 				k += count[j];
// 				d -= x;
// 			}
// 		}
// 		sum += t[i];
// 		count[t[i]]++;
// 		cout << k << " "<<endl;
// 	}
// }
#include<bits/stdc++.h>

// @author : sam000013

#define int long long
#define PI 3.14159265
#define fi(i,start,end) for(int i=0; i<n; i++)
#define pb(x) push_back(x)
#define int long long
#define PI 3.14159265
#define all(v) v.begin(), v.end()
#define endl cout<<"\n" 
#define ll long long
#define dbg(x) cout<<#x<<" "<<x;endl;
#define bye endl;return
using namespace std;
int mod = 1000000007;
template<typename T>

void debug(vector<T> x){
    for(auto e:x){
        cout<<e<<" ";
    }
    cout<<"\n";
}
/*
1
8 6
1 2 4 1 2 4 1 2

*/

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> suffix(n,0); 
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int ans = 0;
    // suffix[n-1] = v[n-1];
    for(int i = n-1; i>=0; i--){
        if(i < n-1)
        suffix[i] = suffix[i+1] + v[i];
        else{
            suffix[n-1] = v[n-1];
        }
        if(i==n-1)
            continue;
        ans = (ans%mod + ((suffix[i+1]%mod)*(v[i]%mod))%mod)%mod;
    }
    cout<<ans;bye;
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t = 1;
    //cin>>t;
    for(int i=1; i<=1; i++){
        solve();
    }
    return 0;
}