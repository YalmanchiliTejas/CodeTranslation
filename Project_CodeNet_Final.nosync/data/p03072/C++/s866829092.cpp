#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
#define MOD 1000000007
using namespace std;
using ll=int64_t;
using pii=pair<int,int>;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
//最大公約数
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
//最小公倍数
int lcm(int a,int b){
   return a*b/gcd(a,b);
}
bool prime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)
        return false;
    }
    return true;
}
int main(){
    int n,a,ans=0;
    cin>>n;
    priority_queue<int> pq;
    rep(i,n){
        cin>>a;
        pq.push(a);
        if(a==pq.top())
        ++ans;
    }
    cout<<ans<<endl;
}