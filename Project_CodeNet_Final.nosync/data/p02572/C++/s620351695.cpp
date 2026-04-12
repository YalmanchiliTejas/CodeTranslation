//Romene                           
                             

                                #include<bits/stdc++.h>
                                
                                #include<string>
                                
                                #include <sstream>
                                using namespace std;
             
                                #define ll long long
                                #define ld long double
                                #define pb push_back
                                #define pf push_front
                                #define f first
                                #define s second
                                #define all(c)  c.begin(), c.end()
                                #define ulli unsigned long long int
                                #define lli long long int
                                #define llv vector< ll >
                                #define llc vector< char >
                                #define lls vector< string >
                                #define llb vector< bool >
                                #define mp make_pair
                                #define endl "\n"
                                #define debg cout<<"HI"<<endl;
                                #define ins insert
                                #define foo(i,n) for(ll i = 0;i<n;i++)
                                #define foa(i,a) for(ll i = 0;i<a.size();i++)
                                #define foe(i,a,b) for(ll i = a;i<=b;i++)
                                #define max3(a,b,c) max(max(a,b),c)
                                #define min3(a,b,c) min(min(a,b),c)
                                #define INF 2147483647
                                #define len length
                                #define sp setprecision(16)
                                #define mod 1000000007
                                
                                 
                                ll powr(ll b,ll m){  
                                  ll ans=1;
                                  while(m>0){
                                  if(m%2==1){
                                  ans=(ans*b)%mod;
                                  }
                                  b=(b*b)%mod;
                                  m=m/2;
                                   
                                      
                                  }
                                  return ans;
                                }
                                 ll gcd1(ll a,ll b){
                                  if(a==0)
                                    return b;
                                  else{
                                    return gcd1( b%a, a);
                                  }
                                 }
                                 ll lcm(ll a, ll b)  
                              {  
                                 return (a*b)/gcd1(a, b);  
                              }  
                                 ll mod1(ll a){
                                  if(a<0)
                                    return -1*a;
                                  else{
                                    return a;
                                  }
                                 }
                              
                                 bool isPrime(int num){
                                if(num==1)return 0;
                                for(int i = 2; i*i <= (num); i++) {
                                   if(num % i == 0) {
                                      return false;
                                      break;
                                   }
                                }
                               

                                return true;
                            }
                             
                                                           
                           
                         
                                      
                                int main(){
                                  #ifndef ONLINE_JUDGE
                                    freopen("input.txt", "r", stdin);
                                    freopen("output.txt", "w", stdout);
                                    #endif
                                    ios::sync_with_stdio(0);
                                    cin.tie(0); cout.tie(0);
                                
                                 
                                     int f1=1;
                                    
                                                           
                                    
                                 for(int y3=0;y3<f1;y3++){
                                int n;
                                cin >> n;
                                ll a[n];
                                foo(i,n)cin >> a[i];
                                ll ans=0;
                                for(int i=1;i<n;i++){
                                  ans=(ans+a[i]*a[i-1])%mod;
                                  a[i]=(a[i]+a[i-1])%mod;
                                }
                                cout << (ans+mod)%mod;
                            }


           



                                           
                                    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
                                
                              
                                
                                                                                       
                                                   
                                 }
                                
