#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll N,a[60];

ll ceil(ll x, ll y){
    if (x<0) return x/y-(x%y!=0);
    else return x/y;
}

bool check(ll t){
    int i;
    ll cnt=0;
    for (i=1; i<=N; i++){
        cnt+=ceil(a[i]+t+1,N+1);
        if (cnt>t) return 0;
    }

    return 1;
}

bool isgood(ll t){
    ll i;
    for (i=t-N; i<=t+N; i++)
        if (i>=0 && check(i)) return 1;
    return 0;
}

int main(){

    cin >> N;

    ll i,sum=0;
    for (i=1; i<=N; i++){
        cin >> a[i];
        sum+=a[i];
    }



    ll l=0,r=2*sum,mid;
    while (l<r){
        mid=(l+r)/2;
        if (isgood(mid)) r=mid;
        else l=mid+1;
    }

    ll res;
    for (i=r-N; i<=r+N; i++)
        if (i>=0 && check(i)){
            res=i;
            break;
        }

    cout << res << "\n";
    return 0;
}
