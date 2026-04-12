#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define print(x) cerr << (#x) << "is "<< x << "\n"
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;

ll arr[N],n;

int solve() 
{ 
    multiset<int> last; 
    for (int i = 0; i < n; i++) { 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
        if (it == last.begin()) 
            last.insert(arr[i]); 
        else { 
            it--; 
            last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
} 

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	f(i,0,n){
		cin >> arr[i];
	}
	cout << solve() << '\n';
	return 0;
}