/******Old_school_@15******/
#include<bits/stdc++.h>
using namespace std;
#define lld               long long int
#define ld                long double
#define pb                push_back
#define ppb               pop_back hellooitsme1
#define mp                make_pair
#define F                 first
#define S                 second
#define nl                '\n'
#define all(c)            (c).begin(),(c).end()
#define rall(c)           (c).rbegin(),(c).rend()
#define sz(c)             (c).size()
#define tr(x,a)           for(auto &a : x)
#define psnt(x,a)         (x).find(a)!=(x).end()
#define vpsnt(x,a)        find(all(x),a)!=(x).end()
#define lexichar(x,y)     lexicographical_compare(x,x+strlen(x),y,y+strlen(y)) //modify the ranges
#define lexistr(x,y)      lexicographical_compare(x.begin(),x.end(),y.begin(),y.end()) 
#define MOD               1000000007
#define pi                3.1415926536
#define tod               1
#define itr(i,a,b)        for(lld i=a;i<=b;i++)
#define itrn(i,a,b)       for(lld i=a;i>=b;i--)
#define iot(n)            for(lld i=0;i<n;i++)
#define pls(n,arr)        lld arr[n]; iot(n)  cin>>arr[i];
#define bye               fflush(stdout)

typedef pair<lld,lld>     pii;
typedef pair<string,lld>  psi;
template <typename T>
bool mycomp(T x,T y){ 
   return (x==y);  //give your condition here
}
bool paircomp(const pair<lld,lld> &x,const pair<lld,lld> &y){ 
return x.second<y.second;
}

int main(){
       ios_base::sync_with_stdio(false);
             cin.tie(0);
            cout.tie(0);
      lld t=1; //cin>>t;  
      while(t--){
          lld x; cin>>x;
          if(x>=30)  cout<<"Yes";
          else  cout<<"No\n";
      }
}
