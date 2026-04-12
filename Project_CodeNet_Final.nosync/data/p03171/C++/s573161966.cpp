                                                //  IT'S NEVER TOO LATE...

            #include <bits/stdc++.h>
            #include <complex>
            #define ll long long

            #define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
            #define forn(i, n) fore(i, 0, n)
            #define fori(i, l, r) fore(i, l, (r) + 1)
            #define sz(v) int((v).size())
            #define all(v) (v).begin(), (v).end()
            #define pb push_back
            #define mp make_pair
            #define ff first
            #define ss second
            
            //#define C complex<int>
            #define X real()
            #define Y imag()

            using namespace std; 

            const double PI = atan(1)*4;
            #define inf 1e9
            const int mod=1e9+7;


            /*struct matrix
            {
                int k;
                vector<vector<ll>> data;
                matrix(int x)
                {
                    k=x;
                    data.resize(x);
                    forn(i,x)
                    data[i].resize(x);
                }

                matrix operator *(matrix m1)
                {
                    int n=m1.data.size();
                    matrix m2(n);

                    forn(i,n)
                    {
                        forn(j,n)
                        {
                            forn(k,n)
                            {
                                m2.data[i][k]+=((m1.data[i][j]%1000000007)*(data[j][k]%1000000007))%1000000007;
                                m2.data[i][k]%=1000000007;
                            }
                        }
                    }


                    return m2;
                }
            };*/


            /*ll dp[30][30],val[100],wt[100];
            ll fpair(ll n,ll k)
            {
                if(n==0 || n<k)
                    return 0;
                if(n==k)
                	return 1;
                if(dp[n][k])
                    return dp[n][k];
                
                return dp[n][k]=(ll)fpair(n-1,k-1) + (ll)k*fpair(n-1,k);
            }*/

            ll dp[3001][3001][2];
			ll solve(vector<int>& v,int i,int j,int turn)
			{
			    if(i>j)
			    {
			        return 0;
			    }
			    if(dp[i][j][turn]!=-1)
			    {
			        return dp[i][j][turn];
			    }
			    if(turn ==1)
			    {
			        return dp[i][j][turn]=max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
			    }
			     return dp[i][j][turn]=min(solve(v,i+1,j,1),solve(v,i,j-1,1));
			    
			}

            int main()
            {

            	#ifndef ONLINE_JUDGE
	            freopen("input.txt","r", stdin);
	            freopen("output.txt", "w", stdout);
	            #endif
            
                ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
             
                int tt=1;
                //cin>>tt;

                while(tt--)
                {
                    //matrix mat(n),m2(n);
                    
                	int n;
				    cin>>n;
				    memset(dp,-1,sizeof(dp));
				    vector<int> v(n+1);
				    ll sum=0;
				    for(int i=1;i<=n;i++)
				    {
				        cin>>v[i];
				        sum=sum+v[i];
				    }
				    ll scoreX=solve(v,1,n,1);
				    ll scoreY=sum-scoreX;
				    cout<<scoreX-scoreY<<"\n";    
				     
                }
                cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";

                return 0;
            }
                            //              NOW IT'S TIME TO WAKE UP... 