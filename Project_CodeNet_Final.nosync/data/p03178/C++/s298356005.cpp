        /*
        Author: Arham_doshi
        @quote "Code like there's no tommorow!"
         ***************************************   UNAUTHORISED COPYING OF CODE PROHIBITED   **********************************
        */
        #include <bits/stdc++.h>
         
        #define int         long long
        #define double      long double
        #define pb          push_back
        #define pf          push_front
        #define pii         pair<int,int>
        #define vi          vector<int>
        #define vii         vector<pii>
        #define mi          map<int,int>
        #define mii         map<pii,int>
        #define all(a)      (a).begin(),(a).end()
        #define rall(a)     (a).rbegin(),(a).rend()
        #define x           first
        #define y           second
        #define sz(x)       (int)x.size()
        #define endl        '\n'
        #define hell        998244353
        #define PI          3.141592653589
        #define bs(v,n)     binary_search(all((v)),(n))
        #define lb(v,n)     lower_bound(all((v)),(n))
        #define ub(v,n)     upper_bound(all((v)),(n))
        #define fo(i,l,u)   for(i=l;i<u;i++)
        #define rfo(i,l,u)  for(i=l;i>=u;i--)
        #define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
        #define _init(b)     memset(b,-1,sizeof(b))
        #define _init0(b)     memset(b,0,sizeof(b))
        #define MOD         1000000007
         
         
         
        using namespace std;
         
        int gcd(int a, int b) {  if (a == 0)  return b; return gcd(b % a, a); }  
        bool mod(double a,double b) {return a/b - floor(a/b);}
        
        int ceil(int n,int k){if(k%n==0){return k/n;}else return (k/n)+1;}
        
        int occurs(vi v,int n){
        auto it=lb(v,n);auto it1=ub(v,n);int x=it1-it;return x;}
         
        int logb(int base, int x) {
            return (log(x) / log(base));
        }
        
        int dp[10005][105],l,n;
        string s;
        
        int digit_sum(int k,int sum,int e){
            int i,x;
            if(e==0){
                if(dp[k][sum]!=-1){
                    return dp[k][sum];
                }
                else if(k==l-1){
                    dp[k][sum]=0;
                    fo(i,0,10){
                        if((sum+i)%n==0){
                            dp[k][sum]++;
                        }
                    }
                    return dp[k][sum];
                }
                else{
                    dp[k][sum]=0;
                    fo(i,0,10){
                        dp[k][sum]+=digit_sum(k+1,(sum+i)%n,0)%MOD;
                    }
                    return dp[k][sum];
                }
                
            }
            else {
                if(k==l-1){
                    x=0;
                    fo(i,0,s[k]-'0'+1){
                        if((sum+i)%n==0){
                            x++;
                        }
                    }
                    return x;
                }
                else{
                x=0;
                fo(i,0,s[k]-'0'){
                    x+=digit_sum(k+1,(sum+i)%n,0)%MOD;
                }
                x+=digit_sum(k+1,(sum+s[k]-'0')%n,1)%MOD;
                    return x;
                    
                }
            }
        
        }
        
        
     
        signed main()
        {
            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
            int i,j,x,d,k;
            cin>>s;
            cin>>n;
            l=s.length();
            _init(dp);
            x=0;
            if(l>1){
                fo(i,0,s[0]-'0'){
                    x=(x+digit_sum(1,(n+i)%n,0))%MOD;
                    
                }
                x=(x+digit_sum(1,(s[0]-'0'+n)%n,1))%MOD;
                if(x!=0){
                    cout<<x-1<<endl;
                }
                else{
                    cout<<MOD-1<<endl;
                }
            }
            else{
                fo(i,1,s[0]-'0'+1){
                    if((i)%n==0)x++;
                }
                cout<<x;
            }
            
            
            return 0;
        }