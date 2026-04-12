#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define Rrep(i,n) for(int i=((int)n-1); i>=0; i--)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 2e15
#define MOD 1000000007

typedef vector<int> vint;
typedef long long ll;



int main()
{
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(15);

        ll n;
        ll x,m;

        //ll size=1;
        

        cin>>n>>x>>m;

        ll sum=x;

        vector<ll> a;
        a.push_back(x);

        ll index;
        
        rep(i,m){
                ll tmp=(a[i]*a[i])%m;
                auto itr=find(a.begin(),a.end(),tmp);
                index=distance(a.begin(),itr);
                if(tmp==0){
                        cout<<sum<<endl;
                        return 0;
                }
                if(itr!=a.end()){
                        break;
                }
                else{a.push_back(tmp);sum+=tmp;}
        }

        ll roop = (n-index)/(a.size()-index)-1;
        ll r = (n-index)%(a.size()-index);

        ll roopsum=0;
        for(int i = index; i < a.size(); i++){
                roopsum += a[i];
        }

        sum += roopsum*roop;
        rep(i,r){
                sum += a[index+i];
        }

        cout<<sum<<endl;
        return 0;
}
