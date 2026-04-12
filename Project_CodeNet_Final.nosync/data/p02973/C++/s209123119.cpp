#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#pragma GCC optimize ("Ofast")
#define rep(i,a,b) for(ll i = (a); i < (b); ++i)
#define iter(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define pb push_back
#define fs first
#define sc second
#define MOD 1000000007
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

inline int modulo(int a, int b) {
  const int result = a % b;
  return result >= 0 ? result : result + b;
}

int mnincr(int arr[], int n)
{
    multiset<int> last;
    for (int i = 0; i < n; i++) {

        multiset<int>::iterator it = last.lower_bound(arr[i]);


        if (it == last.begin())

            last.insert(arr[i]);

        else {
            it--;


            last.erase(it);
            last.insert(arr[i]);
        }
    }
    return last.size();
}


int main()
{
    int arr[100100];
    int n;
    cin >> n;
    rep(i,0,n) cin >> arr[i];
    cout << mnincr(arr,n);
}
