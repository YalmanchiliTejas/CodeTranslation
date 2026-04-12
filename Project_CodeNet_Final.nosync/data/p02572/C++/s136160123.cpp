#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    lint n,x,ans=0,sum=0,mod=1000000007;
    cin>>n;
    vector<lint> vec(n);
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;sum%=mod;
        vec[i]=x;
    }
    for(int i=0;i<n;i++){
        sum-=vec[i];
        if(sum<0)sum+=mod;
        ans+=vec[i]*sum%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
