#include<bits/stdc++.h>
#define ll long long
#define vr(v,n) vector<int> (v)(n)
#define in(name) for(auto &i:name) cin>>i
#define pr(name) for(auto i:name) cout<<i<<" "
#define db(n) cout<<n<<"\n"
#define start_c auto start_clock_time=chrono::high_resolution_clock::now()
#define stop_c auto stop_clock_time=chrono::high_resolution_clock::now()
#define pr_c cout<<"\n"<<chrono::duration_cast<chrono::milliseconds>(stop_clock_time-start_clock_time).count()<<" ms\n"
#define MOD 1000000007
#define pb push_back()
#define srt(v) sort(v.begin(),v.end())
#define test_cases long long test_cases;cin>>test_cases;while(test_cases-->0)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr(i,n) for(ll i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a==b)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}