#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(i) cout << i << endl;
#define debugarr(a) for(auto i : a) cout << i << " ";

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<int> last;

    for(int i = 0; i < n; i++) {
        multiset<int>::iterator it = last.lower_bound(arr[i]);
        if(it == last.begin()) {
            last.insert(arr[i]);
        }else {
            it--;
            last.erase(it);
            last.insert(arr[i]);
        }
    }
    cout << last.size() << endl;
}
