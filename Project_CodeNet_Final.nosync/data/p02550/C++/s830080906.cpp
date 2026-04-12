#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int main(void)
{
    ll n,x, m;
    cin >> n >> x >> m;
    vector<int> id(m, -1);
    vector<int> a;
    int length = 0;
    ll total = 0;
    while (id[x] == -1 && length !=n)
    {
        a.push_back(x);
        id[x] = length;
        length++;
        total += x;
        x = (x * x) % m;
    }
    if(length==n){
        cout<<total<<endl;
        return 0;
    }

    int circleLength=length-id[x];
    ll oneCircleSum=0;
    for(int i=id[x];i<length;i++){
        oneCircleSum+=a[i];
    }

    ll ans=total;
    n-=length;
    ans +=oneCircleSum*(n/circleLength);//一周回った回数分
    n%=circleLength;//回りきらなかった余り
    rep(i,n) ans+=a[id[x]+i];
    cout<<ans<<endl;
    return 0;
}
