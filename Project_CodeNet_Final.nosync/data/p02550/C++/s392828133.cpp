#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define     bit_1(a)       __builtin_popcount(a)
#define     ull            unsigned long long
#define     ll             long long
#define     pb             push_back
#define     pf             push_front
#define     mpr            make_pair
#define     ins            insert
#define     ff             first
#define     ss             second
#define     vi             vector<int>
#define     vl             vector<ll>
#define     vstr           vector<string>
#define     si             set<int>
#define     sl             set<ll>
#define     li             list<int>
#define     pii            pair<int,int>
#define     pll            pair<ll,ll>
#define     mii            map<int,int>
#define     mll            map<ll,ll>
#define     ma             INT_MAX
#define     mi             INT_MIN
#define     mod            1000000007
#define     pi             3.14159265359
#define     e              2.71828182846
#define     inf            1000000000000000LL
#define     all(x)         x.begin(), x.end()
#define     lb(a,b,c)      lower_bound(a,a+b,c)-a
#define     ub(a,b,c)      upper_bound(a,a+b,c)-a
#define     lbv(a,c)       lower_bound(all(a),c)-a.begin()
#define     ubv(a,c)       upper_bound(all(a),c)-a.begin()
#define     srt1(a,b)      sort(a,a+b)
#define     srt2(a,b)      sort(a,a+b,greater<int>())
#define     gcd(a,b)       __gcd(a,b)
#define     lcm(a,b)       (a*(b/gcd(a,b)))
#define     harmonic(n)    0.57721566490153286l+log(n)
#define     mem(a, b)      memset(a, b, sizeof(a))
#define     orderset1      tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define     orderset2      tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

ll ar[1000005];

int main()
{
    /*string str;
    cin>>str;
    int sz=str.size();
    if(str[sz-1]!='s')cout<<str<<"s\n";
    else cout<<str<<"es\n";*/
    /*int n;
    cin>>n;
    int A[n+5],B[n+5],cnt=0;
    for(int i=0;i<n;i++)cin>>A[i]>>B[i];
    for(int i=0;i<n;){
        if(A[i]==B[i]){
            cnt=0;
            while(A[i]==B[i]){
                i++;
                cnt++;
                if(i>=n)break;
            }
            if(cnt>=3){
                cout<<"Yes\n";
                return 0;
            }
        }
        else i++;
    }
    cout<<"No\n";*/
    /*int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/i;j++){
            int m=i*j;
            int dif=n-m;
            if(dif>0 && dif<n)cnt++;
        }
    }
    cout<<cnt<<endl;*/
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans=x;
    mll mark;
    mll pos;
    mark[ans]=1LL;
    ar[1]=x;
    pos[x]=1;
    ll pos2,pos3,sum2=ans;
    bool flag=false;
    for(ll i=2;i<=n;i++){
        ans=((ans%m)*(ans%m))%m;
        ar[i]=ans;
        if(mark[ans]){
            pos2=pos[ans];
            pos3=i;
            flag=true;
            break;
        }
        mark[ans]=1;
        pos[ans]=i;
        sum2+=ans;
    }
    if(!flag){
        cout<<sum2<<endl;
        return 0;
    }
    ll sum=0;
    for(ll i=pos2;i<pos3;i++)
        sum+=ar[i];
    ll pad=((n-pos2)+1)/(pos3-pos2);
    sum*=pad;
    for(ll i=pos2;i<pos2+((n-pos2)+1)%(pos3-pos2);i++)
        sum+=ar[i];
    for(ll i=1;i<pos2;i++)sum+=ar[i];
    cout<<sum<<endl;
}


