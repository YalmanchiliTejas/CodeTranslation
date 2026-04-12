                #include <bits/stdc++.h>
                using namespace std;
                #define int long long
                #define fi first
                #define se second
                #define pi pair<int,int>  
                #define pb push_back

                // dont forget to initialize global variables inside main() ;
                int mod = 1e9 + 7;
                
                int func(string &s,string &t,int k){
                    int ans=0;
                    for(int i=k;i<k+(int)t.size();i++){
                        if( s[i]!=t[i-k] )
                            ans++;
                    }
                    return ans;
                }
                int32_t main() {
                
                ios::sync_with_stdio(false);
                cin.tie(0);
                cout.tie(0);

                int tt=1;//;cin>>tt; 
                
                
                while( tt-- ){

                    int n;cin>>n;
                    vector<int > a(n);
                    for(int i=0;i<n;i++)
                        cin>>a[i];
                    vector<int > s(n);
                    for(int i=n-1;i>=0;i--){
                        if( i==n-1 ){
                            s[n-1]=a[n-1];
                        }
                        else{
                            s[i] = a[i]+s[i+1];
                        }
                    }
                    int ans=0;
                    for(int i=0;i<n-1;i++){
                        ans = (ans%mod + (a[i]%mod)*(s[i+1]%mod))%mod;
                    }
                    cout<<ans<<endl;
                }
                return 0;
            }

                        
