#include <bits/stdc++.h>
using namespace std;
#define int long long
#define dd double
#define fi first
#define se second
#define reverse(x) reverse(x.begin(),x.end())
#define sortsi(x) sort(x.begin(),x.end())
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
int MAX = 1e9 + 7; 

template <class T>
void print(vector<T>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
 
template <class T>
void print(vector<vector<T>>&v){
    for(int i=0;i<v.size();i++){
       for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
       cout<<endl;
    }
    cout<<endl;
}
int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
void solve(){
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ts = 0;
    for(int i=0;i<n;i++)ts+=v[i]%MAX;
    int tss = ((ts%MAX)*(ts%MAX))%MAX;
    int ss = 0;
    for(int i=0;i<n;i++)ss+=((v[i]%MAX)*(v[i]%MAX))%MAX;
    ss = ss%MAX;
    // cout<<tss<<" "<<ss<<endl;
    int num = (tss%MAX - (ss%MAX) + MAX)%MAX;
    num = ((num%MAX)*(modInverse(2,MAX)%MAX))%MAX;
    cout<<num<<endl;
    
}

int32_t main(){
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
