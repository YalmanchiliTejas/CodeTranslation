//is there any case of -1 or any special corner cases ?
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pi pair<int,int>
#define all(v) v.begin(),v.end()
#define zeros(arr) memset(arr,0,sizeof(arr));
#define precise(num)  cout<<fixed; cout << std::setprecision(num)
#define nl cout<<"\n";
#define test int t;cin>>t;while(t--) 
const int maxx  = 3*1e5 , limit = 9*1e18 , MOD=1e9+7;
#define boost  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n';
int32_t main(){
    int n,a,m;
    cin>>n>>a>>m;
    
    
    vector<int>ans;
    
    map<int,int>mark;
    
    int i=1;
    int res=0;
    int val = 0;
    for(i = 1; i <= n ; i++ ){
        
        int curr = a%m;
        // cout<<curr<<endl;
        if(mark[curr] < 2 ){
            ans.pb(curr);
            res+=curr;
            mark[curr]++;
        }else{
            val = curr;
            break;
        }
        a=(a*a)%m;
    }
    // cout<<val<<endl;
    
    int curr=val;
    if(i == n){
        // cout<<"case1\n";
        cout<<res<<endl;
    }else{
        int cp = 0;
        int len=0;
        val=0;
        for(int i = 0 ; i < ans.size() ; i++ ){
            if(ans[i] == curr){
                cp++;
            }
            if(cp==1){ 
                len++ ; 
                val+=ans[i]; 
                
            }
        }
        
        if(i+len > n){
            
            for(int j = i ; j<= n ; j++ ){
                int curr=a%m;
                res+=curr;
                a=(a*a)%m;
            }
            
        // cout<<"case2\n";
            cout<<res<<endl;
            
        }else{
            
            
            int kita = (n-i+1)/len;
            
            res = res + kita*val;
            
            // cout<<kita<<" "<<val<<endl;
            i = i + len*kita;
            a=(curr)%m;
            for(int j = i; j<=n; j++ ){
                a=a%m;
                res+=a;
                a=(a*a)%m;
            }
            cout<<res<<endl;
            
        // cout<<"case3\n";
            
        }
        
    }
    
    
    
    
}