#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define S second
#define F first
#define pb push_back
#define M1 1000000007
#define M2 998244353
#define maxn 100000
#define plli pair<lli,lli>
#define setit set<lli>::iterator seti
#define mapit map<lli,lli> ::iterator mapi
#define MP make_pair
#define MT make_tuple
#define PI 3.14159265358979323846
// map      iterator->first  iterator.first
// map      mp[key]=value
// set      *s.begin()
// vector   v[j]=value
// pair     p.first p.second
// vector of pairs v[j].first v[j].second
// tuple    get<index>(tuple_name)
// vector of tuples get<index>(v[j])  sort(v.begin(),v.end())
//priority queue .top() .pop() .push()
// __gcd(x,y)
#define mini(x,y) (y + ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1))))
#define maxi(x,y) (x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))))
#define fr(j,a,b) for(j=a;j<b;j++)

lli power(lli x, lli y, lli p)
{   lli res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {   if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli i, j, x, k, n, y,  p, q, l, t, z, m, w, r;
    cin >> t;
    if (t >= 30) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    // for(i=0;i<t;i++){
    //     cin>>n;
    //     lli a[n];
    //     for(j=0;j<n;j++){
    //         cin>>a[j];
    //     }

    // }
}