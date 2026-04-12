#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int n;cin>>n;
    int res[26];
    rep(i,26)res[i]=INF;
    rep(_,n){
        string s;
        cin>>s;
        int k =s.length();
        int sum[26];
        rep(i,26)sum[i]=0;
        rep(i,k){
            sum[s[i]-'a']++;
        }
        rep(i,26)res[i]=min(res[i],sum[i]);
        }
    string ans;
    for(char i ='a';i<='z';i++){
        rep(x,res[i-'a'])ans+=i;
    } 
    cout<<ans<<endl;
    }