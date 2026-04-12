#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll sum[N];
ll n,x,mod;
int main() {
    cin >> n >> x >> mod;
    map<int, int> m;
    ll s=-1,e,i=1;//s是循环节起点，e是终点
    while(1) {
        sum[i]=x +sum[i-1];
        if (m[x] == 0) m[x]++;
        else if (m[x] == 1) {
            if(s==-1) s = i;
            m[x]++;
        } else{
            e = i - 1;
            break;
        }
        x=((x%mod)*(x%mod))%mod;
        i++;
    }
    ll k=(e-s+1);
    s-=k,e-=k;
    ll ans=0;
    ll res=sum[e]-sum[s-1];//循环节大小
    ans=sum[s-1]+res*((n-(s-1))/k)+(sum[s+(n-(s-1))%k-1]-sum[s-1]);
    cout<<ans;
    return 0;
}
