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
    lint n,k,roop,extra,ans=0;cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(int i=k+1;i<=n;i++){
        roop=n/i;
        extra=n%i;
        ans+=roop*(i-k)+max(0LL,extra-k+1);
    }
    cout<<ans<<endl;
}
