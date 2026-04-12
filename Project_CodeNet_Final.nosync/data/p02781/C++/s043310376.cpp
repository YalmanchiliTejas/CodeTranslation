 #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
#define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e18
 #define sm         -2e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
  
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("gin.txt", "r", stdin);
    freopen("gout.txt", "w", stdout);
   
    #endif
}

int an,k;
string n,cur;

void recur(int i,int rm,string cur,int fl)
{
    if(rm==0)
    {
        an++;
        return ;
    }
    if(i==101 )
    {
        if(rm==0)
        {
         an++;
         cout<<cur<<endl;     
            
        }
        return ;
    }

    if(fl==1)
    {
     int c = 101-i;
            if(c < rm) return ;

            if(rm==2) c = (c*(c-1))/2;
            else if(rm==3) c = (c*(c-1)*(c-2))/6;
            an += c * (int)pow(9,rm);
    return ;
    }
    

   

    for(int j=1;j<=9;j++)
    {
        string temp = cur;
        temp[i] = '0'+j;
        if(temp <= n && rm > 0 )
        {
            if(j < (n[i]-'0'))
            recur(i+1,rm-1,temp,1);
            else recur(i+1,rm-1,temp,fl);
        }
    }
     if(n[i] > '0') fl=1;

   recur(i+1,rm,cur,fl);
}

void solve()
{
 
 cin >> n >> k;
 
 while(sz(n)!=101)
 {
   n.insert(n.begin(),'0');
 }

 cur.assign(101,'0');

 an =0 ;

 recur(0,k,cur,0);

 cout<<an<<endl;
 
}


int32_t main()
{
  pr_init();
  fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
   // cout << "Time taken by function: "
   //       << duration.count() << " microseconds" << endl; 

 }
      
      