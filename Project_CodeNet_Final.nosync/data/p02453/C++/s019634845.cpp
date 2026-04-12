#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
//#define LOCAL
using namespace std;
typedef long long ll;
const int mx=1e5+10;

int main() {
#ifdef LOCAL
ifstream fin("1.txt");
streambuf*p;
p=cin.rdbuf(fin.rdbuf());
#endif // LOCAL
ll value[mx];
ll n;
cin>>n;
for(int i=0;i<n;i++) cin>>value[i];
sort(value, value+n);

ll q;
cin>>q;

for(ll i=1;i<=q;i++){
    ll k;
    cin>>k;
    ll sub=lower_bound(value, value+n, k)-value;
    printf("%lld\n", sub);
}

#ifdef LOCAL
fin.close();
#endif // LOCAL
}

