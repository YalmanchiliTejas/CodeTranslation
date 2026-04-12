#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F(i,m,n) for(ll i=m;i<n;i++)
#define Fr(j,n,m) for(ll j=n;i>=m;i--)
#define vll vector<ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpll vector< pll >
/*-------------------------------------*---------------------------------------*/

#define godspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout << #x << "=" << x << endl
#define cout_array(a) for(auto x: a){ cout<<x<<" ";}cout<<endl

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
string dec_bin(ll x){
    string result;
    while(x>0){
        result.push_back(x%2 + 48);
        x = (x-(x%2))/2;
    }
    reverse(result.begin(),result.end());
    return result;
}
const ll MAX_PRIME = 1e9+7;
const ll INF = 1e18;

ll pow_2(ll factor){
    ll count = 0;
    while(factor%2==0){
        count+=1;
        factor/=2;
    }
    if(factor==1)return count;
    else return -1;
}

/*I NEED YOU TO WORK FOR TWO HOURS ON THIS NO MATTER WHAT....THE RESULT DOESN'T MATTER.....ITS ALL ABOUT YOUR EFFORTS.
---------------------------------------------------------------------------------------------------------------------*/

int main(){
    godspeed
    ll t;
    cin>>t;
    if(t>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
