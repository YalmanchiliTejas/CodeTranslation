




/*
///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================
vector<int>inp;
vector<ll>sav;
ll dp[45+5][5];
ll sv=0;

ll dp2( int pos, int f ){
if(pos==inp.size()) return 1;
if(f==1) return (1<<( inp.size()-pos ));
else return sav[pos];
}

ll outp(int pos, int f, ll cnt){
   // cout<<pos<<" "<<f<<" posf"<<endl;
    if( pos==inp.size() ) return cnt;
    int limit;
    if( dp[pos][f]!=-1 ) return dp[pos][f];

    if(f==0)
        limit= inp[pos];
    else limit= 1;
    int i; ll res=0;
    for(i=0;i<=limit;i++){
          //  if(pos==0 && i==0) continue;
        //  cout<<i<<" =i"<<endl;
        int new_f= f;
        if(i< inp[pos] && f==0 ) new_f=1;
       // else new_f=1;
        if(i==1){  ll koi= dp2(pos+1, new_f); res+= outp(pos+1,new_f,cnt+koi);            } //+dp2(pos+1,new_f);  }
        else { res+= outp(pos+1,new_f,cnt);  }

    }
dp[pos][f]= res;// sv=res;
 return dp[pos][f];
}



ll call(ll a){
if(a<0) return 0; if(a==0) return 1;
inp.empty(); int kcn=0;
while(a){
 inp.pb(a%2); ll pk= (1<< (kcn)  )*(a%2); kcn++; if( sav.size()==0 ) sav.pb(pk); else sav.pb( sav[ sav.size()-1 ]+pk );   a/=2;
}
reverse(inp.begin(),inp.end());
reverse(sav.begin(),sav.end());
memset( dp,-1,sizeof (dp) );
 return outp(0,0,0);
}


int main()
{
    //cout << "Hello world!" << endl;
  //  cout<<(1<<30)<<endl;

    int i; ll ot= call(13);


    cout<<ot<<" "<< (1<<ot)<< endl;
    for(i=0;i<inp.size();i++)
        cout<<inp[i];
    cout<<endl;








    return 0;
}



*/







/*
  //

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================
vector<int>inp;
ll dp[45+5][5];
ll sv=0;

void outp(int pos, int f){
    cout<<pos<<" "<<f<<" posf"<<endl;
    if( pos==inp.size() ) {cout<<0<<endl; sv=0; return; }
    int limit;
    if( dp[pos][f]!=-1 ) cout<<dp[pos][f]<<endl;

    if(f==0)
        limit= inp[pos];
    else limit= 1;
    int i; ll res=0;
    for(i=0;i<=limit;i++){
          //  if(pos==0 && i==0) continue;
          cout<<i<<" =i"<<endl;
        int new_f= f;
        if(i< inp[pos] ) new_f=1;
       // else new_f=1;
        if(i==1){ outp(pos+1,new_f); res+=sv+1; }
        else {outp(pos+1,new_f);  res+= sv; }

    }
dp[pos][f]= res; sv=res;
cout<<dp[pos][f]<<endl;
}



void call(ll a){
//if(a<0) return 0; if(a==0) return 1;
inp.empty();
while(a){
    inp.pb(a%2); a/=2;
}
reverse(inp.begin(),inp.end());
memset( dp,-1,sizeof dp );
  outp(0,0);
}


int main()
{
    //cout << "Hello world!" << endl;
   // cout<<call(11)<<endl;
   call(3);






    return 0;
}


*/




  //
/*
///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================

struct cmp{

    bool operator () ( const pair<int,int>p1, const pair<int,int>p2 )const{
int ln1= p1.YY-p1.XX+1, ln2= p2.YY-p2.XX+1;
if(ln1==ln2) return p1.XX < p2.XX;
return ln1>ln2;
}

};



int main()
{
    //cout << "Hello world!" << endl;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set< pair<int,int>, cmp >st;
        vector<int>vc; vc.resize(n+1); fill(vc.begin(),vc.end(),0); int i;
        st.insert( { 0, n-1 } );

        for(i=1;i<=n;i++){
            pair<int,int> curr= *st.begin();
            st.erase(st.begin());
            int id= ( curr.first+ curr.second )/2;
            vc[id]=i;
            if( id>curr.first) st.insert({ curr.first, id-1 });
            if( id<curr.second ) st.insert( {id+1,curr.second} );

        }

        for(i=0;i<n;i++){
            cout<<vc[i]<<" ";
        }cout<<endl;

    }


    return 0;
}

*/



/*
  // LEARN prefix sum, CF D. Constant Palindrome Sum

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================



int main()
{
   // cout << "Hello world!" << endl;
   int t; cin>>t;
   while(t--){
    int n,k; cin>>n>>k; vector<int>ispossible, changes; ispossible.resize(k+k+5); changes.resize(k+k+5);
    fill( all(ispossible),0 ); fill( all(changes),0 );
    vector<int>arr; int i; arr.pb(0);
    for(i=0;i<n;i++){
        int xx; cin>>xx; arr.pb(xx);
    }

    for(i=1;i<=n/2;i++){
        int L= min( arr[i], arr[ n-i+1 ] ), R= max( arr[i], arr[n-i+1] );
        ispossible[L+R]+=2; ispossible[L+R+1]+=-2;
        if(L+1<= L+R && L+R<=k+R+1){
            if(L+1<=L+R-1){
                 ispossible[ L+1 ]+=2; ispossible[L+R]+=-2; changes[L+1]+=1; changes[L+R]+=-1;
            }
            if( L+R+1<=k+R+1 ){
                     ispossible[ L+R+1 ]+=2; ispossible[k+R+1]+=-2; changes[L+R+1]+=1; changes[k+R+1]+=-1;
            }
        }
        else{
        ispossible[ L+1 ]+=2; ispossible[k+R+1]+=-2; changes[L+1]+=1; changes[k+R+1]+=-1; }


        if( 2<=L ){
               ispossible[ 2 ]+=2; ispossible[L+1]+=-2; changes[2]+=2; changes[L+1]+=-2;
        }

        if( k+R+1<=k+k ){
            ispossible[k+R+1]+=2; ispossible[k+k+1]+=-2; changes[k+R+1]+=2; changes[k+k+1]+=-2;
        }
    }
        int ot=n;
    for(i=1;i<=k+k+2;i++){
        ispossible[i]+= ispossible[i-1]; changes[i]+=changes[i-1];
        if(ispossible[i]>=n) ot= min(ot, changes[i] );
      //  cout<<i<<" "<<ispossible[i]<<" "<<changes[i]<<" deb"<<endl;
    }

    cout<<ot<<endl;

   }

    return 0;
}


*/






  //
/*
///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================
*/
/*
ll dp[30][1005]; ll n,m;
vector<ll>vc,poss,vall;
ll DP(ll pos, ll val){
if(pos<=1) return 1;
if(val>n) return 0;
if(dp[pos][val]!=-1) return dp[pos][val]%mod;

ll i; dp[pos][val]=0;
for(i=1;i<=val;i++){
    dp[pos][val]= (dp[pos][val]%mod + DP(pos-1,i)%mod)%mod;

                    }
  vc.pb(dp[pos][val]); poss.pb(pos); vall.pb(val);
    return dp[pos][val]%mod;
}

*/ //
/*
vector<int>vc;
int dp[110][52][52][2];

int DP( int range, int o1, int z0, int oe ){

if(o1<0 or z0<0) return inf;
if(range==0) return 0;

if(dp[range][o1][z0][oe]!=-1) return dp[range][o1][z0][oe];
int xx= inf;

if((vc[range]==0 && oe==1) or (vc[range]==1 && oe==0)) { dp[range][o1][z0][oe]=inf; return dp[range][o1][z0][oe]; }

if(vc[range]!=-1){
xx= min(xx, DP(range-1,o1-( vc[range]==1 ),z0-( vc[range]!=1 ),1)+ ( vc[range]!=1 )  );
xx= min(xx, DP(range-1,o1-( vc[range]==1 ),z0-( vc[range]!=1 ),0)+ ( vc[range]!=0 ) );
}


else{
    int fxx= oe;
xx= min(xx, DP(range-1,o1-( oe==1 ),z0-( oe!=1 ),1)+ ( oe!=1 )  );
xx= min(xx, DP(range-1,o1-( oe==1 ),z0-( oe!=1 ),0)+ ( oe!=0 ) );

}



dp[range][o1][z0][oe]=xx;
return dp[range][o1][z0][oe];
}

int main()
{
    int n; cin>>n; int i; int one=0, zero=0; memset(dp,-1,sizeof dp); vc.pb(-5);
    for(i=0;i<n;i++){
        int xx; cin>>xx;
        if(xx){vc.pb(xx%2);}
        else vc.pb(-1);
    }

    if(n==1){ cout<<0<<endl; exit(0);}

    one= n/2+(n%2); zero=n/2;
    //cout<<one<<" "<<zero<<" zo"<<endl;
    int cnt= min( DP(n,one,zero,0), DP(n,one,zero,1) );
    cout<<cnt<<endl;




    return 0;
}


*/




  //3 - C

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pii pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1e5+10;
/// ===========================================  template  =======================================================


/*

{
"cmd": ["g++.exe","-std=c++17", "${file}", "-o", "${file_base_name}.exe", "&&" , "${file_base_name}.exe<inputf.in>outputf.in"],
"shell":true,
"working_dir":"$file_path",
"selector":"source.cpp"
}
 // 

*/



void solve(){
  


return;

}




int main()
{
   // cout << "Hello world!!" << endl; 
    FASTIO
//
    //int t; scanf("%d",&t);  while(t--){  solve(); } 

//  


int xx; cin>>xx;
if(xx>=30) cout<<"Yes"<<endl;
else cout<<"No"<<endl;





// 

// return 0;
}


/*
 
  //4 - D

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;


// 



    return 0;
}

*/





/*   //5 - E

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/





/*  //6 - F

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/







/*  //7 - G

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/





/*  //8 - H

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/






/*  //9 - I

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/





/*   //10 - J

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================


int main()
{
    cout << "Hello world!" << endl;






    return 0;
}

*/



/*
  // UVA- 6982- Dhoni Bowlers
  // codechem: https://www.codechef.com/problems/AMR14C
///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================



int main()
{
    int t; cin>>t;
    while(t--){
     ll n,m,x; cin>>n>>m>>x;
     ll a[n+2], cumulitive_mod[m+x+2]; ll ans=0;  // a[] is used to store given values (mod), 'ans' is used to store output :)
     // at first, I just saved number of a[i]%m & then cumulitive mod in cumulitive_mod array
     int i; ll xx; map<ll,ll>mp; // map will be used to store a[i]%m individually

    for(i=0;i<m+x+2;i++)
        cumulitive_mod[i]=0;

     for(i=0;i<n;i++){
        cin>>a[i]; a[i]= a[i]%m;
        cumulitive_mod[ a[i] ]++; mp[ a[i] ]++;
     }

     for(i=1;i<m+x+2;i++){
        cumulitive_mod[i]+= cumulitive_mod[i-1];   // being cumulitive
       }

     for(i=0;i<m;i++){
        if( mp[i]==0 ) continue;   // if i has no occurrence as mod, why should I think about it?
        if(i<=x){ ans+= mp[ i ]*( cumulitive_mod[x-i]  ); }  // 0 <= j <= x-i
        ans+= mp[ i ]* ( cumulitive_mod[m+x-i]-cumulitive_mod[m-i-1] );   // m-i <= j <= m+x-i
     }

     cout<<ans<<endl;
    }

    return 0;
}


*/




/*
  //6949 - Knockout Racing

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================

int pos(int x, int y, int t){  // to find position at t-th second, if track is x to y;
int dis= abs(x-y);
int dir= t/dis; int amn= t%dis;
if(dir%2==0){
return amn+x;
}

else{
return y-amn;
}

}


int main()
{
   // cout << "Hello world!" << endl;

   int n,m;
   while( cin>>n>>m ){
    vector< pair<int,int> >cars; vector< pair< pair<int,int>, int > >query;
    int i,j; int x,y,t;
    for(i=0;i<n;i++){
        cin>>x>>y; cars.push_back( {x,y} );
    }

    for(i=0;i<m;i++){
        cin>>x>>y>>t; query.push_back( {{x,y},t} );
    }
    vector<int>ans; ans.resize(m+5); fill(ans.begin(),ans.end(),0);

    for(i=0;i<n;i++){
            int xx= cars[i].first, yy= cars[i].second;
    for(j=0;j<m;j++){
        pair<int,int>ur=query[j].first; int x1= ur.first, x2= ur.second, tt= query[j].second;
       // if( yy<x1 or xx>x2 ) continue;
        int up_pos= pos(xx,yy,tt);
       // cout<<xx<<" "<<yy<<" "<<tt<<" ++"<<endl;
        if( up_pos<=x2 && up_pos>=x1 ) ans[j]++;
    }

    }


    for(i=0;i<m;i++)
        cout<<ans[i]<<endl;

   }

    return 0;
}

*/




/*
  // uva 6988- Gabba sprint O(s)

///===========================================  TAREQ ABRAR  =======================================================
#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
/// ===========================================  template  =======================================================

int first_pos(int m, int n, int p){
    if(m%p==0 or m==1) return m;
    int xf;
    xf= m-m%p+p;
    if( xf>n ) return m+xf-n-1;
    else
        return xf;
}


int main()
{
    //cout << "Hello world!" << endl; 4 1 4 2 3

    int t; cin>>t; int kas=0;
    for(kas=1;kas<=t;kas++){
        int n,m,s,p,q; cin>>n>>m>>s>>p>>q; int d= n-m+1;
//int pp=p, qq=q;
     //  p= p%d; q= q%d;
        int i;
        int f_p=0, f_q= 0; int cn=0;
       // if(f_p==f_q) cn++;
       // cout<<f_p<<" "<<f_q<<endl;

        for(i=1;i<=s;i++){
            f_p+=p; f_q+=q;
            while(f_p>n) f_p= m+f_p-n-1; while(f_q>n) f_q= m+f_q-n-1;
            //if(f_p==0) f_p=n; if(f_q==0) f_q=n;
            if(f_p==f_q) cn++;
           // cout<<f_p<<" "<<f_q<<endl;
        }

        cout<<cn<<endl;


    }






    return 0;
}



*/





