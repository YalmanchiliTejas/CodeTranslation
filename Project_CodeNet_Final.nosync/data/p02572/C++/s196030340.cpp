    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    //--<for debugging>
    #define whatis(x) cout << #x << " is " << x<<" ";
    #define whatisl(x) cout << #x << " is " << x<<"\n";
    #define parr(array,end)for(ll loop=0;loop<end;loop++)cout<<array[loop]<<" ";cout<<"\n";
    #define lline cout<<"\n";
    #define errorl(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout<<"\n";}
    #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout<<"___";}
        
    void err(istream_iterator<string> it) {}
    template<typename T, typename... Args>
    void err(istream_iterator<string> it, T a, Args... args) {
        cout << *it << " = " << a <<" , ";
        err(++it, args...);
    }
    //--</for debugging> 
    #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
    #define testcase ll tt; cin >> tt; while(tt--)
    #define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define pb push_back 
    #define vars ll h,i,j,k,d,l,p,q,r,x,y,a,b,c,v,var,n,m,z,s,ans,ind1,ind2,flag,limit1,limit2,limit3,mod;string str;
    #define vll vector<ll>
    #define pll pair<ll,ll>
    #define sll set<ll>
    #define pint pair<int,int>
    const ll INF=1e9+7;
    const ll MOD=1e9+7;
    const string yes="YES\n";
    const string no="NO\n";
    int main()
    {
        boost vars
        //freopen("input.txt","r",stdin);
        //freopen("input.txt","w",stdout);
        cin>>n;
        ll arr[n],pre[n+1]={0};
        pre[0]=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            pre[i+1]=arr[i]+pre[i];
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            var=(pre[n]-pre[i+1])%MOD;
            ans=(ans+(arr[i]*var)%MOD)%MOD;
        }
        cout<<ans;
        
    }