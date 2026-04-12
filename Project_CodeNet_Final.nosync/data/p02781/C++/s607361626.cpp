#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pb push_back 
#define eb emplace_back
#define fn for(int i =0 ;i <n;i++)
#define fn1 for( int i =1;i<=n;i++)
#define fm for(int j =0 ;j <m;j++)
#define fm1 for(int j =1;j<=m;j++)
#define fi first
#define se second
#define E endl
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const int N = 2e6+5;
const int INF = 1e18L;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
int ar[N];
int dp[N];
int  pow1(int  x, int  y){
int  ans = 1;
  while(y>0){
    if (y&1)
    {
      ans*=x;
    }
    x *= x;
    y>>=1;
  }
return ans;
} 
signed main(){
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif
  IOS;
  int T=1;
  // cin >> T;
  while(T--){
    string s;
    cin>>s;
    int k;
    cin >> k;
    if(k==1){
        int q= s.size()-1, ans = 0;    
        ans+=9*q;
        ans+=(int)(s[0]-'0')-1;
        ans+=1ll;
        return cout << ans,0;
    }
    int n =s.size();
    string t(n-1,'0');
    for(int i=0 ;i <k-1;i++) t[n-2-i]='1';
    int cnt=0;
    vector<int>C;
    for(int i=pow1(10ll,k-1)+1;i<pow1(10ll,k);i++){
        int ii=i;
        int flag=1;
        while(ii){
            if((ii%10)==0) flag=0;
            ii/=10;
        }
        if(flag) cnt++;
        if(flag) C.pb(i);
    }
    int mul=1,den=1;
    for(int i=0 ;i < k;i++){
        mul*=(n-1-i);
        den*=(i+1);
    }
   int ans=1ll*(mul/den)*cnt;
    do{
        vector<int>p;
        p.pb(0);
       for(int i= 0;i<n-1;i++) if(t[i]=='1') p.pb(i+1);
        string t1="1";
        t1+=t;
        int ss = t1.size();
        vector<int>d(k);
        for(int i:C){
            int ii=i;
            for(int j =0 ;ii>0 && j < k;j++){
                d[k-1-j]=ii%10;
                ii/=10;
            }
            int ok = 0 ;
            for(int j =0 ;j < k;j++){
            	if(p[j]>ss ){
            		 ok =1;
            		 break;
            		}

           	 t1[p[j]]='0'+d[j];	
            } 
            if(!ok && t1<=s) ans++;
        }
    }while(next_permutation(all(t)));
    cout << ans;
  
  
  }
  cerr << "Time Taken : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
  return 0;
}
