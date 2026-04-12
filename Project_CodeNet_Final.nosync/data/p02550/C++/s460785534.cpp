#include<bits/stdc++.h>
#include <iostream> 
#include <string> 
#define lli long long int
#define deb1(x) cout<<#x<<" :: "<<x<<"\n";
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define deb3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define deb(v) for(lli i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }
#define all(a) a.begin(),a.end()
#define ll long long
using namespace std;
#define f first
#define sd second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(x) (ll)x.size()
#define vl vector<lli>
#define pii pair<lli,lli>
lli mod=998244353;
using namespace std;
lli t,n,u,x,y,k;
const lli N = 100001;
lli po(lli i,lli j){
    lli ans=1;
    for(lli l=1;l<=j;++l)ans*=i;
    return ans;
}
int main(){
    fast
     t=1;
//    cin>>t;
    while(t--){
        cin>>n>>x>>k;
        map<lli,lli>m;
        vl a;
        a.push_back(x);
        m[x]=0;
        lli cnt=1,fl=0,s=x;
        for(int i=2;i<=n;++i){
            y=a[a.size()-1]*a[a.size()-1];
            y=y%k;
            s+=y;
//            deb3(i,y,s)
            if(m[y]!=0){
//                deb1(m[y])
                lli sum=0,r=0,ans=0;
                vl b;
//                for(int j=0;j<a.size();++j)cout<<a[j]<<" ";
//                cout<<endl;
                for(int j=0;j<m[y];++j)ans+=a[j];
                for(int j=m[y];j<i-1;++j){
                    sum+=a[j];
                    b.push_back(sum);
                    ++r;
                }
//                deb2(r,sum)
                lli an=((n-i+1)/r)*sum;
//                deb1(an)
                if((n-i+1)%r!=0){
//                    for(int j=0;j<b.size();++j)cout<<b[j]<<" ";
//                cout<<endl;
//                deb1((n-i+1)%r)
                    an+=b[(n-i+1)%r-1];
                }
                ans+=an+sum;
//                deb1(ans)
                cout<<ans<<endl;
                fl=1;
                break;
               
                
            }else m[y]=cnt;
            ++cnt;
            a.push_back(y);
        }
        if(!fl)cout<<s<<endl;
        
        
    }
}