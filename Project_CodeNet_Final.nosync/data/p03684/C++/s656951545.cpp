#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef pair<int,ii>iii;
const int N=1e5+5;
vector<ii>a,b;
map<ii,int>check;
vi pset,s;
bool cmp(ii a,ii b )
{
    return a.second<b.second;
}
void init(int n)
{
    pset.assign(n+1,-1);
    s.assign(n+1,1);
    for(int i=1;i<=n;i++){
        pset[i]=i;
    }
}
int findset(int i)
{
    if(pset[i]==i)return i;
    else return pset[i]=findset(pset[i]);
}
void unionset(int i,int j)
{
    int x=findset(i),y=findset(j);
    if(s[x]>s[y]){
        pset[y]=x;
        s[x]+=s[y];
    }
    else{
        pset[x]=y;
        s[y]+=s[x];
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(check[ii(x,y)])continue;
        else{
            a.push_back(ii(x,y));
            b.push_back(ii(x,y));
            check[ii(x,y)]=++cnt;
        }
    }
    init(a.size()+1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),cmp);
    priority_queue<iii,vector<iii>,greater<iii> >q;
    //for(int i=1;i<=a.size();i++)cout<<pset[i]<<endl;
    for(int i=0;i<a.size()-1;i++){
        int x=a[i].first,y=a[i].second;
        q.push(iii(a[i+1].first-x,ii(check[a[i]],check[a[i+1]])));
    }
    for(int i=0;i<a.size()-1;i++){
        int x=b[i].first,y=b[i].second;
        q.push(iii(b[i+1].second-y,ii(check[b[i]],check[b[i+1]])));
    }
    while(!q.empty()){
        int c=q.top().first,u=q.top().second.first,v=q.top().second.second;
        q.pop();
        if(findset(u)!=findset(v)){
            ans+=c;
            unionset(u,v);
        }
    }
    cout<<ans;
}