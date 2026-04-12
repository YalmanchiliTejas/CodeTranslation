#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define INF 1000000000000000005ll
using namespace std;

int n,m;
vector<pair< pair<ll,ll>, ll> > interval;
struct S {
    ll mx,prop;
}tree[maxn*3+5];

void add(int node,int b,int e,int i,int j,ll x)
{
    if(j<b || i>e) return;
    if(b>=i && e<=j) {
        tree[node].prop+=x;
        if(tree[node].mx!= -INF)
        tree[node].mx+=x;
        else
        tree[node].mx = x;
      //  cout<<"tree node "<<b<<" "<<e<<" "<<tree[node].mx<<endl;
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid =(b+e)/2;
    add(left,b,mid,i,j,x);
    add(right,mid+1,e,i,j,x);
    tree[node].mx = max(tree[left].mx,tree[right].mx)+tree[node].prop;
}

ll query(int node,int b,int e,int i,int j,ll carry)
{
    if(j<b || i>e) return -INF;
    if(b>=i && e<=j) {
     //   cout<<"qqqq "<<b<<" "<<e<<" "<<tree[node].mx<<endl;
        return tree[node].mx+ carry;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    ll q1 = query(left,b,mid,i,j,tree[node].prop+carry);
    ll q2 = query(right,mid+1,e,i,j,tree[node].prop+carry);
    return max(q1,q2);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=3*n;i++) tree[i].mx = -INF;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        interval.push_back(make_pair(make_pair(b,a),c));
    }
    sort(interval.begin(),interval.end());
    int sz = interval.size();
    int p = 0;
    for(int i=1;i<=n;i++) {
        ll val = query(1,1,n,0,i-1,0);
        val = max(val,0ll);
       // if(val!=0)
        //cout<<i-1<<" "<<val<<endl;
        add(1,1,n,i,i,val);
        while(p<sz && interval[p].first.first == i) {
         //   cout<<" interval "<<interval[p].first.second<<" "<<interval[p].first.first<<endl;
            add(1,1,n,interval[p].first.second, interval[p].first.first,interval[p].second);
         //   cout<<query(1,1,n,1,interval[p].first.first,0)<<endl;
            p++;
        }
    }
    cout<<max(0ll,query(1,1,n,1,n,0))<<endl;

    return 0;
}
