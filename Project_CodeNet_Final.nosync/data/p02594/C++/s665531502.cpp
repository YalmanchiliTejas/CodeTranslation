                    #include <bits/stdc++.h>
                            #include<string>
                            using namespace std;
                            #define pb push_back
                            #define endl '\n'
                            #define all(x) (x).begin(), (x).end()
                            #define forn(i, n) for (int i = 0; i < (int)(n); i++)
                            #define init(arr,value) memset(arr,value,sizeof(arr))
                            #define test unsigned int tet;cin >> tet;while(tet--)
                            #define sz(a) int((a).size())
                            typedef long long ll;
                            typedef unsigned long long ull;
                            typedef long double ld;
                            typedef vector<int> vi;
                            typedef pair<int, int> pii;
                            typedef pair<ll, ll> pll;
                            #define sf scanf 
                            #define pf printf 
                            #define SUM(v) accumulate(all(v),ll(0))
                            #define present(container, element) (container.find(element) != container.end())
                            #define cpresent(container, element) (find(all(container),element) != container.end())
                            int max(int a,float b){
                                if(a>b)
                                   return a;
                                return b;
                            }
                            ll gcd(ll a,ll b){
                                if(a%b==0)
                                    return b;
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
                            bool isprime(int x){
                                for(int i=2;i<=sqrt(x);i++){
                                    if(x%i==0)
                                    return 0;
                                }
                                return 1;
                            }
                            
                           
                            
                            
                          int main(){
                                int x;
                            	sf("%d",&x);
                            	if(x>=30)pf("Yes");
                            	else pf("No");
                                    
                                    
                          
                                cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
                    	return 0;
                            }