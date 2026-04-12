#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vi vector<ll>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define el printf("\n")
#define pb push_back
#define f first
#define s second
#define arrondi(a) (long long)floor(a+0.5);
#define NIL -1
ll N=500005;
ll MAX=9223372036854775807;
ll MOD=1000000007;
long double PI =4*atan(1);

int MinimumNumIncreasingSubsequences(vector<ll> arr,int n)
{
    multiset<ll> last;

    // last element in each  increasing subsequence
    // found so far
    for (int i = 0; i < n; i++) {

        // here our current element is arr[i]
        multiset<ll>::iterator it = last.lower_bound(arr[i]);

        // iterator to the first element larger
        // than or equal to arr[i]
        if (it == last.begin())

            // if all the elements in last larger
            // than or to arr[i] then insert it into last
            last.insert(arr[i]);

        else {
            it--;

            // the largest element smaller than arr[i] is the number
            // before *it which is it--
            last.erase(it); // erase the largest element smaller than arr[i]
            last.insert(arr[i]); // and replace it with arr[i]
        }
    }
    return last.size(); // our answer is the size of last
}
int main()
{
	IOS;
    cout.precision(30);
    int n; cin >> n; vector<ll> A(n,0);
    for (int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    ll ans=MinimumNumIncreasingSubsequences(A,n);
    cout << ans;
    return 0;
}
