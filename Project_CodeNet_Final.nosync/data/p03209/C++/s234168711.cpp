#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define eps 0.000001
#define endl '\n'

using namespace std ;

#define MAXN 100001
/*lli spf[MAXN];  
void sieve();
set<lli> factors(lli x);
lli power(lli x,lli y,lli p);
*/


/*char a[1000001];
lli cnt[4*1000001],x[4*1000001]={0},y[4*1000001]={0};

class node
{
    public :
        lli cnt,x,y;
};

inline void build(lli n,lli s,lli e)
{
    if(s==e)
    {  
        cnt[n]=0;
        if(a[s]=='(') x[n]=1;
        else y[n]=1;
        return;
    }

    lli mid=(s+e)/2 ;

    build(2*n,s,mid);
    build(2*n+1,mid+1,e);
    lli k=min(x[2*n],y[2*n+1]);
    cnt[n]=cnt[2*n]+cnt[2*n+1]+2*k;
    x[n]=x[2*n]+x[2*n+1]-k;
    y[n]=y[2*n]+y[2*n+1]-k;

}

inline node query(lli n,lli s,lli e,lli l,lli r)
{
    node n1;
    
    if(e<l || s>r)
    {
        n1.cnt=-1;
        n1.x=-1;
        n1.y=-1;
        return n1;----
    }

    else if(s>=l && e<=r)
    {
        n1.cnt=cnt[n];
        n1.x=x[n];
        n1.y=y[n];
        return n1;
    }

    lli mid = (s+e)/2 ;
    node n2=query(2*n,s,mid,l,r);
    node n3=query(2*n+1,mid+1,e,l,r);

    n1.x=n1.y=n1.cnt=0;

    if(n2.x != -1) 
    {
        n1.x+=n2.x;
        n1.y+=n2.y;
        n1.cnt+=n2.cnt;
    }
    
    if(n3.x != -1)
    {
        n1.x+=n3.x;
        n1.y+=n3.y;
        n1.cnt+=n3.cnt;
        
        if(n2.x !=-1)
       {
        lli k=min(n2.x,n3.y);
        n1.x-=k;
        n1.y-=k;
        n1.cnt+=2*k;
        }  
    }

    return n1;
}*/

/*void dfs(lli q, lli par);


*/
//void getZarr(string str, lli Z[]);


lli len[51],pat[51];

lli rec(lli i,lli x,lli cnt)
{
    if(i == 0) return cnt+1;

    if(x==0 || x==1) return cnt;

    if(x < 1+len[i-1])
     return  rec(i-1,x-1,cnt);

    if(x == 1+len[i-1])
        return cnt+pat[i-1];

    if(x == 2+len[i-1])
        return cnt+pat[i-1] + 1;

    if(x > 2+len[i-1])
        return rec(i-1,x-2-len[i-1],cnt+pat[i-1] + 1);

}


int main()
{  
    
    lli n,x;
    cin>>n>>x;

    

    len[0]=1;
    pat[0]=1;

    loopl(i,1,51)
    {
        len[i]=2*len[i-1]+3;
        pat[i]=2*pat[i-1]+1;
    }

    cout<<rec(n,x,0)<<endl;


}

/*void sieve() 
{ 
    spf[1] = 1; 
    loopl(i,2,MAXN) 
        spf[i] = i; 
    for (lli i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (lli i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (lli j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    }

} 

multiset<lli> factors(lli x) 
{ 
    multiset<lli> pr; 
    while (x != 1) 
    { 
        pr.insert(spf[x]); 
        x = x / spf[x]; 
    } 
    return pr; 
}

*/

/*
void dfs(lli q,lli root) 
{
    vis[q]=1;
    
    ans[q]=1;

    for(auto x: v[q])
    {
        if(!vis[x])
        {
            if(a[x]==a[root] && x<root) continue;
            if(a[x]<a[root] || a[x]>a[root]+d) continue;
            dfs(x,root);
            ans[q]=(ans[q]*((ans[x]+1)%mod))%mod ;
        }
    }
        
}
*/



/*void getZarr(string str, lli Z[])
{
    lli n = str.length();
    lli L, R, k;
    L = R = 0;
    for (lli i = 1; i < n; ++i){
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        } else {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
*/


/*
lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;   
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;  
        x = (x*x) % p;   
    } 
    return res; 
} 
*/  

