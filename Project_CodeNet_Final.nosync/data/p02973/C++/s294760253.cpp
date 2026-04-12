#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 100005;
int n , ara[N];
int tree[4 * N];

void update(int node,int L,int R,int pos,int val)
{
    if(pos < L or pos > R)return;
    if(pos == L and pos == R){
        tree[node] = val;
        return;
    }
    int mid = (L + R)/2;
    update(2 * node,L,mid,pos,val);
    update(2 * node + 1,mid + 1,R,pos,val);
    tree[node] = max(tree[2 * node] ,tree[2 * node + 1]);
}
int query(int node,int L,int R,int from,int val)
{
    int mid = (L + R)/2;
    if(L >= from){
        if(L == R){
            if(tree[node] > val)return L;
            return 2e9;
        }
        if(tree[2 * node] > val){
            return query(2 * node,L,mid,from,val);
        }else if(tree[2 * node + 1] > val){
            return query(2 * node + 1,mid + 1,R,from,val);
        }else{
            return 2e9;
        }
    }else{
        if(R < from)return 2e9;
        return min(query(2 * node,L,mid,from,val),query(2 * node + 1,mid + 1,R,from,val));
    }
}
int main()
{
    FastRead
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> ara[i];
        update(1,1,n,i,ara[i]);
    }

    set<int>st;
    for(int i = 1;i <= n;i++)st.insert(i);

    int done = 0,ans = 1,val = -1;
    while(st.size() > 0){
        auto it = st.upper_bound(done);
        if(it == st.end()){
            done = 0;
            val = -1;
            ans++;
            continue;
        }
        int in = query(1,1,n,*it,val);
        if(in == 2e9){
            done = 0;
            val = -1;
            ans++;
            continue;
        }
        update(1,1,n,in,0);
        done = in;
        st.erase(in);
        val = ara[in];
    }
    cout << ans << "\n";

}


