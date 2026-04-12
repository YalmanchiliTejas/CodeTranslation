//-------All power is within you,you can do Anything and Everything.---------//
 
    #include <bits/stdc++.h>
    using namespace std;
  
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ M $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
 
    #define pb push_back
    #define MP make_pair
    #define F first
    #define S second
    #define sc(x) scanf("%lld",&x)
    #define pf(x) printf("%lld\n",x)
    #define int long long
    #define all(x) x.begin(),x.end() 
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define rfo(i,b,a) for(int i=b;i>=a;i--)
    #define mem( a, val ) memset(a, val, sizeof( a ) )
    #define deci( x ) cout<<fixed<<setprecision( x );
    #define bitcount( x ) __builtin_popcountll( x )
    #define endl "\n" 
    
    #define XOX 
    
    typedef vector<int> vi;
    typedef pair<int,int> pi; 
    
    const int MOD =  1000000007 ;
    const int MAX = 3e3 + 7;
    const int INF = 1e15;
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DEB $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
    
    #define deb(x) cout<<#x<<" "<<x<<endl;


    vector<string> vec_splitter(string s) 
    {
        for(char& c: s) c = c == ','?  ' ': c;
        stringstream ss; ss << s;
        vector<string> res;
        for(string z; ss >> z; res.push_back(z));
        return res;
    }
    void debug_out(vector<string> args, int idx) { cerr << endl; }
    template <typename Head, typename... Tail>
    void debug_out(vector<string> args, int idx, Head H, Tail... T) 
    {
        if(idx > 0) cerr << ", ";
        stringstream ss; ss << H;
        cerr << args[idx] << " = " << ss.str();
        debug_out(args, idx + 1, T...);
    }
    
    #ifdef XOX
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
    #else
    #define debug(...) 42
    #endif

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ V $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//  
    
    int i,j,k,t,n,q,l,r,mid;

//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ F $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//

    int dpd[MAX][MAX];
    int a[MAX];

    void solve()
    {
        cin>>n;
        fo(i,0,n)
        cin>>a[i];

        rfo(L,n-1,0)
        {
            fo(R,L,n)
            {
                if(L==R)
                    dpd[L][R]=a[L];
                else
                    dpd[L][R]=max(a[L]-dpd[L+1][R],a[R]-dpd[L][R-1]);
            }
        }
        cout<<dpd[0][n-1]<<endl;
        
    }
    
//*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*//
//                          GAME STARTS FROM HERE                            //
 
    int32_t main() 
    {
    
        // int start,stop=clock();
        // cout<<"time:"<<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl;
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        // sc(t);while(t--)
        // cin>>t;while(t--)
            solve();
    
        return 0;
    }