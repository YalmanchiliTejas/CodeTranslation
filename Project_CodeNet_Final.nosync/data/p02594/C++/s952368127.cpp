// यथा चतुर्भिः कनकं परीक्ष्यते निघर्षणच्छेदनतापताडनैः।
// तथा चतुर्भिः पुरुषः परीक्ष्यते त्यागेन शीलेन गुणेन कर्मणा॥
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define ll long long
#define M 1000000007
#define fors(i,n) for(int i=0;i<n;++i)
#define fore(i,a,b) for(int i=a;i<=b;++i)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vv std::vector<int>
#define mapii std::map<int,int>
#define mpaci std::map<char,int>
#define umapii std::unordered_map<int,int>
#define umapci std::unordered_map<char,int>
#define seti std::set<int>
#define useti std::unordered_set<int>
#define qi std::queue<int>
#define qc std::queue<char>
#define sti std::stack<int>
#define stc std::stack<char>
#define endl "\n"
#define test(i) cout<<i<<endl
#define tests(i) cout<<"i: "<<i<<endl;
#define itrt int t; cin>>t; fors(i,t)
#define itr1 int t; cin>>t;
#define ff first
#define ss second
#define pb push_back
#define vmp make_pair
#define ppb pop_back
#define sorta(a,n) sort(arr,arr+n)
#define sortv(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end() 
#define printv(v) for(auto x: v){ cout<< x << " ";}
#define pi 3.141592653589793238
void file(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
bool sortdesk(const pair<int,int> &a, const pair<int,int> &b){return a.ff>b.ff;}
bool sortdesv(const pair<int,int> &a, const pair<int,int> &b){return a.ss>b.ss;}
bool sortascv(const pair<int,int> &a, const pair<int,int> &b){return a.ss<b.ss;}
bool sortasck(const pair<int,int> &a, const pair<int,int> &b){return a.ff<b.ff;}
bool is_prime(int n){if(n==1){return false;}int i=2;while(i*i<=n){if(n%i==0){return false;}i+=1;}return true;}
int gcd(int a, int b){if (b == 0){return a;} return gcd(b, a % b);}
int cntdiv(int n){int cnt=0;for(int i=1;i<=sqrt(n);++i){if(n%i==0){if(n/i==i)++cnt;else{cnt = cnt + 2;}}}return cnt;}
// lld posnegmod(lld x,lld mod){return (x%mod+mod)%mod;}
// int findTrailingZeros(int n){ 
// 	int count = 0;
// 	for (int i = 5; n / i >= 1; i *= 5){count += n / i;} 
// 	return count;
// }
// bool prime[1000001];
// lld ar[1000001];
// void SIE(){
//     for(ll i=1;i<=1000000;i++){
//     	prime[i]=true;}
//     for (ll j=2; j*j<=1000000; j++){
//         if (prime[j] == true){
//             for (ll i=j*2; i<=1000000; i += j)
//                 prime[i] = false;
//         }
//     }
// }
// void primesum(){
//     for(i=2;i<=1e6;i++){
// 		if(prime[i]) ar[i]=ar[i-1]+i;
// 		else ar[i]=ar[i-1];
// 	}
// }
// bool cmp(pair<lld, lld> a, pair<lld, lld> b) {
//     if (a.first != b.first) {
//         return a.first > b.first;
//     }
//     return a.second < b.second;
// }
// lld fact(lld n);
// lld nCr(lld n,lld r){return fact(n) / (fact(r) * fact(n - r));}
// lld fact(lld n){ lld res = 1; for(lld i = 2; i <= n; i++){res = res * i;}return res;} 
// const int maxi = 1e6+10;
// vector<int> v[maxi];
// long long a[maxi];
// void dfs(int x,int y){
//     a[x]+=a[y];
//     for(int i:v[x]){
//         if(i!=y){
//             dfs(i,x);
//         }
//     }
// }

void test_case(){
    int n;
    cin>>n;
    if(n>=30){
        cout<<"Yes";
        return;
    }
    cout<<"No";
}

int main(){
    fastio;
    file();
    // pre();
    // SIE();
    int T=1;
    // int T;
    // cin>>T;
    for(int nr=1;nr<=T;++nr) {
        // cout<<"Case #"<<nr<<": ";
        test_case();
    }
}