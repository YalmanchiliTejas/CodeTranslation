#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ldb long double
#define pb push_back
#define popb pop_back
#define ins insert
#define si size()
#define sof sizeof()
#define be begin()
#define en end()
#define all(v) v.be,v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define G(a,b) get<a>(b)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define ump unordered_map
#define forr(i,a,n) for(lli i=a;i<n;i++)
#define rfor(i,n,a) for(lli i=n;i>=a;i--)
#define fore(i,a,n) for(lli i=a;i<=n;i++)
#define maxe *max_element
#define mine *min_element
#define JaiHindDosto ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define nl cout<<endl;
#define o(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout<<a<<" "<<b<<"\n"
#define o3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define c4(a,b,c,d) cin>>a>>b>>c>>d;
#define c5(a,b,c,d,e) cin>>a>>b>>c>>d>>e;
#define c6(a,b,c,d,e,f) cin>>a>>b>>c>>d>>e>>f;
#define vlli vector <lli>
#define slli set<lli>
#define mlli map<lli,lli>
#define grt greater<>()
#define mod 1000000007
#define inp(a,n) forr(i,0,n)cin>>a[i];
#define out(a,n) forr(i,0,n)o(a[i]);nl;
#define printdecimal(a,n) cout<<setprecision(n)<<fixed<<a; //round of krke
#define indexed_set_lli tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define indexed_set_string tree<string,null_type,less<string>,rb_tree_tag,tree_order_statistics_node_update>
#define fbo(a) find_by_order(a)  //returns a pointer to element
#define indexof(a) order_of_key(a)  //returns index
#define yess cout<<"Yes\n"
#define noo cout<<"No\n"
#define yesno(f) if(f) noo ; else yess; //f=0 means yes f is condition
using namespace std;

lli countSubarrays(lli arr[],
                   lli n, lli k)
{
    lli start = 0, end = 0,
        count = 0, sum = arr[0];

    while (start < n && end < n) {

        // If sum is less than k,
        // move end by one position.
        // Update count and sum
        // accordingly.
        if (sum < k) {
            end++;

            if (end >= start)
                count += end - start;

            // For last element,
            // end may become n
            if (end < n)
                sum += arr[end];
        }

        // If sum is greater than or
        // equal to k, subtract
        // arr[start] from sum and
        // decrease sliding window by
        // moving start by one position
        else {
            sum -= arr[start];
            start++;
        }
    }

    return count;
}
inline lli modadd(lli n,lli m){
    lli sum = ((n+m)%mod+mod)%mod;
    return sum;
}
inline lli modsub(lli n,lli m){
    lli diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}

inline lli modpro(lli n,lli m){
    lli pro = ((n*m)%mod+mod)%mod;
    return pro;
}
inline lli pow(int x,int y){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
inline lli powmod(lli x,lli y){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x);
        y = y >> 1;
        x = modpro(x , x);
    }
    return res;
}
bool sortbysec(const pair<lli,lli> &a,
              const pair<lli,lli> &b)
{
    return (a.second < b.second);
}

lli min(lli a, lli b){
    if(a>b){
        return b;
    }
    return a;
}

lli max(lli a, lli b){
    if(a>b){
        return a;
    }
    return b;
}
lli nc2(lli x){
return ((x)*(x-1))/2;
}
string DecToBin(lli n){
    string s="";
    while(n!=0){
      //  s=to_string(n%2)+s;
        n/=2;
    }
    return "0"+s;
}

lli SolveBin(string s){
    lli ans=0;
    lli prod=1;
    rfor(i,s.si-1,0){
        ans+=prod*(s[i]-48);
        prod*=2;
    }
    return ans;
}
lli n;
 map<lli,lli> parent;
 map<lli,lli> Rank;
 map<lli,lli> Siz;

void makeset(){
    for(lli i=1;i<n+1;i++){
        parent[i]=i;
        Siz[i]=1;
    }
}

lli find(lli i){                            // find by path-compression
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}


void Union(lli i,lli j){                    //union by rank
    lli irep=find(i),irank,jrank,isz,jsz;
    lli jrep=find(j);

    if(irep==jrep){
        return;
    }else{
         irank = Rank[irep];
         jrank = Rank[jrep];
         isz=Siz[irep];
         jsz=Siz[jrep];
        if(irank>jrank){
            parent[jrep]=irep;
            Siz[irep]+=Siz[jrep];
        }else if(jrank>irank){
            parent[irep]=jrep;
             Siz[jrep]+=Siz[irep];
        }else{
            parent[jrep]=irep;
            Siz[irep]+=Siz[jrep];
            Rank[irep]++;
        }
    }
}
lli phi(lli n)
{
  int res=n;
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      while(n%i==0)n/=i;
      res-=res/i;
    }
  }
  if(n>1)res-=res/n;
  return res;
}



int main() {
    JaiHindDosto;
	lli test=1;
//	cin>>test;
    lli wow = test;
	while(test--){
        lli n;
        cin>>n;
        if(n>=30)
        cout<< "Yes"<< endl;
        else cout<<"No\n";









    }
	return 0;
}






















