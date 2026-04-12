#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
const ll inf = 1e10;



int n;
pair<ll,ll> a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i].first>>a[i].second;
	if (a[i].first>a[i].second) {
	    swap(a[i].first, a[i].second);
	}
    }


    ll l1=inf,r1=0,l2=inf,r2=0;
    for (int i=0; i<n; i++) {
	l1=min(l1,a[i].first);
	r1=max(r1,a[i].first);
	
	l2=min(l2,a[i].second);
	r2=max(r2,a[i].second);
    }

    ll ans = (r1-l1)*(r2-l2); //global min and global max are in different sets
    


    
    ll len = max(r1,r2) - min(l1,l2);

    sort(a,a+n);
    reverse(a,a+n);



    //init multiset with elements from `second`
    multiset<ll> ms;
    for (int i=0; i<n; i++) ms.insert(a[i].second);


    //global min and global max are both in first set
    //this means that we're trying to minimize range in the second set
    //

    //iterate first set from hi to lo,
    //->this keeps an "upper bound" on the high values that contribute from first set
    
    //(5,6) swapping in the 5 is an improvement on the upper bound
    //(3,300) but we have to wait until here to swap in the 3 for 5 to become the upper bound
    //...

    
    for (int i=0; i<n; i++) {
	//swap `second` with `first` (i.e, swap with something smaller)
	
	ms.erase(ms.find(a[i].second)); ms.insert(a[i].first);
	
	ll cur = len*(*ms.rbegin() - *ms.begin());
	//watch(cur);
	ans = min(cur, ans);
    }
  
    
    cout<<ans<<endl;  

    return 0;
}
