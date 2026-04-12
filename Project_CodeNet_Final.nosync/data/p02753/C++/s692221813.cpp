#include<bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define ull unsigned long long int  // ranges from (0 - twice of long long int)
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define mod 1000000007LL
#define llpair pair<ll,ll>
#define INF 1000000000000000000ll
#define np next_permutation
#define PI acos(-1)
#define deb(x) cout<<#x<<" "<<x<<endl;
//ALWAYS USE ll DATA TYPE FOR INTEGER(FASTER THAN INTEGER AS WELL AS SOMETIMES WITHOUT USE LONG UR ANSWER WILL NOT ACCEPTED) && DOUBLE FOR DECIMAL VALUE
template<typename T> // for removing front element from the vector
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
template<typename R> // for removing back element from the vector or can directly
void pop_back(std::vector<R> &v) // use vec.pop_back() function...
{
    if (v.size() > 0) {
        v.erase(v.begin()+v.size()-1);
    }
}

bool isprime(ll n)  //IN  O(sqrt(n))
{
    if(n<=1) return false;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
            return false;

    return true;
}

vector<ll> factors(ll n){    //IN  O(sqrt(n))

    vll v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            if((n/i)!=i)
            v.pb(n/i);
        }
    }
    return v;
}

ll power(ll a, ll n)  // using Binary Exponential in TC O(logn)
{                     // Self Written By </ME> :)
    ll res=1;
    while(1)
    {
        if(n%2){
            res=res*a; n--;
        }
        if(n==0) break;
        a=a*a; n/=2;
    }
    return res;
}

ll ts(ll arr[],int l,int r,int x) // ternary search to find x in sorted array arr
{
    
    while(l<=r)
    {
        ll mid1= l+(r-l)/3;
        ll mid2= r -(r-l)/3;
        if(arr[mid1]==x || arr[mid2]==x)
            return 1;
        if(x<arr[mid1])
            r=mid1-1;
        else if(x>arr[mid2])
            l=mid2+1;
        else
        {
            l=mid1+1;
            r=mid2-1;
        }
    }

    return -1;
}

int main() {
    //auto start = chrono::high_resolution_clock::now();
    fio;
    ll t=1;
    //cin>>t;
    while(t--)
    {
      string s; cin>>s;
      int flag1=0,flag2=0;
      for(int i=0;i<s.length();i++)
      {
        if(s[i]=='A')
            flag1=1;
        else if(s[i]=='B')
            flag2=1;
      }

    if(flag1==1 && flag2==1)
    cout<<"Yes"<<"\n";
    else
        cout<<"No"<<"\n";   

    }

    
    //auto finish = chrono::high_resolution_clock::now();
    //cerr << "Time elapsed: " << (chrono::duration<long double>(finish-start)).count() << "s\n";
    return 0;
}



