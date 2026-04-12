#include <bits/stdc++.h>
        #define s(a) cin >> a;
        #define s2(a,b) cin >> a>> b;
        #define s3(a,b,c) cin >> a>> b>> c;
        #define s4(a,b,c,d) cin >> a>> b >> c >> d;
        #define sp(b) cout << b << "\n";
        #define sp2(b,c) cout << b << " "<<c <<endl; 
        #define sp3(a,b,c) cout <<a <<" "<< b << " "<<c <<endl; 
        #define p(a) //////printf("%lld\n",a);
        #define p2(a,b) //////printf("%lld %lld",a,b);
        #define pm(a) //////printf("a\n");
        #define test(t) while(t>0)
        #define sl(a) a.length()
        #define f(a,b,c) for(a=b;a<c;a++)
        #define fr(a,b,c) for(a=c-1;a>=0;a--)
        #define v(a,b) vector<a> b;
        #define pb(a,b) a.push_back(b);
        #define ll long long
        #define mem(a,b) memset(a,b,sizeof(a));
        #define fillar(ar,n) f(i,0,n) s(ar[i]);
        #define diff(a,b) abs(a-b);
        using namespace std;
        #define MOD 1000000007
        #define flush fflush(stdout);
struct flist
{
    int val;
    int pos;
    
};
ll mincomp[100001];
ll maxcomp[100001];
ll mx=1e5+1;
ll getans(ll start,ll end,ll minn,ll maxx,ll com,ll *ar){
    //printf("start=%lld,end=%lld\n",start,end );
    //printf("mnn=%lld,maxx=%lld\n",minn,maxx );
    if(start>end){
        return 0;
    }
    if(start==end){
        if(com==0){
            ar[start]=minn;
            //printf("1.ar[%lld]=%lld\n",start,ar[start] );
        }
        else{
            return 0;
        }
    }
    ll range=end-start+1;
    ll maxxx=maxcomp[range];
    ll minnn=mincomp[range];
    if(com<minnn || com > maxxx){
        return 0;
    }
    int i;
    ll remain=com-(range-1);
    f(i,minn,maxx+1){
        ll left=i-minn;
        ll right=maxx-i;
        ll minbound=mincomp[left]+mincomp[right];
        ll maxbound=maxcomp[left]+maxcomp[right];
        //printf("left=%lld,right=%lld\n",left,right );
        if(remain>=minbound&&remain<=maxbound){
            if(remain-mincomp[left] <=maxcomp[right]){
                ar[start]=i;
                //printf("2.ar[%lld]=%lld\n",start,ar[start] );
                getans(start+1,start+left,minn,i-1,mincomp[left],ar);
                getans(start+left+1,end,i+1,maxx,remain-mincomp[left],ar);
                break;
            }
            else if(remain-maxcomp[left]>=mincomp[right]){
                ar[start]=i;
                //printf("3.ar[%lld]=%lld\n",start,ar[start] );

                getans(start+1,start+left,minn,i-1,maxcomp[left],ar);
                getans(start+left+2,end,i+1,maxx,remain-maxcomp[left],ar);
                break;
            }
        }

    }
    return 1;


}
int main(){
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int i,j,k;
        int n;
        s(n);
        ll x=n*800;
        ll y=(n/15)*200;
        printf("%lld\n",x-y);

}

          