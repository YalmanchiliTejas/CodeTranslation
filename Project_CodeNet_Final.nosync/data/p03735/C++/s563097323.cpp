#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const long long MAXN = 2e5+5;
long long ans=1e18;
multiset<long long> a;
multiset<long long> b;
pair<long long,long long> arr[MAXN];
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        if(arr[i].first>arr[i].second){
            swap(arr[i].first,arr[i].second);
        }
        a.insert(arr[i].first);
        b.insert(arr[i].second);
    }
    ans = (*a.rbegin()-*a.begin())*(*b.rbegin()-*b.begin());
    sort(arr+1,arr+n+1);
    for(long long i=1;i<=n;i++){
        long long x = arr[i].first;
        long long y = arr[i].second;
        a.erase(a.find(x));
        b.erase(b.find(y));
        a.insert(y);
        b.insert(x);
        ans = min(ans,(*a.rbegin()-*a.begin())*(*b.rbegin()-*b.begin()));
    }
    cout<<ans<<endl;
}