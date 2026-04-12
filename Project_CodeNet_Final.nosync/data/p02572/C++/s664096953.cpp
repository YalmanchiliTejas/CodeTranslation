            #include<bits/stdc++.h>
                                                using namespace std;
                                                #define pb push_back
                                                #define endl '\n'
                                                #define mod 1000000007
                                                #define forn(i, n) for (int i = 0; i < (int)(n); i++)
                                                #define REPa(i,b) for(int i=1;i<=b;i++)
                                                #define REP(i,n) for(int i=0;i<n;i++)
                                                #define init(arr,value) memset(arr,value,sizeof(arr))
                                                #define test unsigned int tet;cin >> tet;while(tet--)
                                                #define sz(a) int((a).size())
                                                #define vi vector<int>
                                                typedef long long ll;
                                                typedef unsigned long long ull;
                                                typedef long double ld;
                                                typedef pair<int, int> pii;
                                                typedef pair<ll, ll> pll;
                                                #define sf scanf
                                                #define pf printf
                                                #define all(x) (x).begin(), (x).end()
                                                #define SUM(v) accumulate(all(v),ll(0))
                                                #define present(container, element) (container.find(element) != container.end())
                                                #define cpresent(container, element) (find(all(container),element) != container.end())
                                                int max(int a,float b){
                                                    if(a>b)
                                                      return a;
                                                      return b;
                                                }
            
                                                ll gcd(ll a,ll b){
                                                  if(a%b==0) return b;
                                                  else
                                                      return gcd(b,a%b);
                                                  }
                                                ll lcm(ll a,ll b){
                                                  return a*b/gcd(max(a,b),min(a,b));
                                                  }
                                                bool sort_pair(pair<int,int>a,pair<int,int> b){
                                                  return a.first<b.first;
                                                 }
                                                bool sort_pair_(pair<int,int>a,pair<int,int>b){
                                                  return a.second>b.second;
                                        }
                                                
                                           
                                                int main(){
                                                    int n;
                                                    sf("%d",&n);
                                                    int a[n];
                                                    ll b[n]={};
                                                    
                                                    for(int i=0;i<n;i++)sf("%d",&a[i]);
                                                    b[n-1]=a[n-1];
                                                    for(int i=n-2;i>=0;i--){
                                                        b[i]=(a[i]+b[i+1])%1000000007;
                                                    }
                                                    ll sum=0;
                                                    for(int i=0;i<n-1;i++){
                                                        sum=(sum+(a[i]%1000000007*b[i+1]%1000000007)%1000000007)%1000000007;
                                                    }
                                                    pf("%lld",sum%1000000007);
                                                    
                                                }
            
