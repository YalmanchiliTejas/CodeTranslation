    /* Aditya0412 */
    #include <bits/stdc++.h>
    using namespace std; 
    #define int long long 
    #define pb push_back 
    #define vii vector < int > 
    #define pii pair < int , int >
    #define fi first
    #define all(a)      (a).begin(),(a).end()
    #define si(x)       (int)((x).size())
    #define debug(x)    cout<<#x<<" is "<<(x)<<endl;cout.flush();  
    #define se second 
    #define endl        '\n'
    #define f(i,a,b)    for(int i=a;i<b;i++)
    #define mem(a,x)          memset(a,x,sizeof(a))
    #define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    const int  mod=998244353;
    // const int  mod = 1000000000+7;
    const int  N=200000+6;
    #define M_PI           3.14159265358979323846

    // int x2[]={+1,-1,+0,+0};
    // int y2[]={+0,+0,+1,-1};
    // int x2[]={+0,+0,+1,-1,-1,+1,-1,+1};
    // int y2[]={-1,+1,+0,+0,+1,+1,-1,-1};
    // int x2[]={-2,-2,-1,-1,+1,+1,+2,+2};
    // int y2[]={-1,+1,-2,+2,-2,+2,-1,+1};

    // === Debug macro starts here ===

    int recur_depth = 0;
    #ifdef DEBUG
    #define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
    #else
    #define dbg(x)
    #endif
    template<typename Ostream, typename Cont>
    typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
        os<<"[";
        for(auto& x:v){os<<x<<", ";}
        return os<<"]";
    }
    template<typename Ostream, typename ...Ts>
    Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
        return os<<"{"<<p.first<<", "<<p.second<<"}";
    }

    // === Debug macro ends here ===

    main() 
    {
        fastIO;
        int n,x,m;
        cin>>n>>x>>m;
        bool vis[m+5];mem(vis,false);
        vector< int > v;int val;
        while(1)
        {
            if(vis[x])
            {
                val=x;break;
            }
            else
            {
                vis[x]=true;
                v.pb(x);
                x=x*x;
                x%=m;

            }
            
        }

        int nn=si(v);
        int ans=0;
        f(i,0,nn)
        {
            if(n>0)
            {
                ans+=v[i];
                n--;
            }
        }
        dbg(ans);
        int ind;
        if(n>0)
        {
            dbg(val);
            f(i,0,nn)
            {
                if(v[i]==val)
                {
                    ind=i;break;
                }
            }
            int sum=0;
            f(i,ind,nn)
            sum+=v[i];
            nn=(nn-1-ind+1);
            ans+=(sum*(n/nn));
            int left=n%nn;
            for(int i=ind;left>0;left--,i++)
            {
                ans+=v[i];
            }
            dbg(ans);
        }
        cout<<ans;


        
    } 