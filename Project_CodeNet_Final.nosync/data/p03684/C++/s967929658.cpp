# pragma GCC optimize("O3")
# include <bits/stdc++.h>
# define maxn 100005
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define sz(x) (int)((x).size())
//# define int ll
using namespace std;
#define pii pair<int,int>
const int mod = 1e9 + 7;

const int inf = INT_MAX;
vector<pair<int,int>>v,vv;
set<pair<int,int>>s;

bool viz[maxn];
vector< pii > ans;
vector< pii > vec[maxn];
int sum,n,x,y,z,m,vizited;
priority_queue< pair< int,pii >, vector< pair< int,pii > >, greater < pair< int,pii > > > Q;

void prim()
{
    viz[1] = 1;
    for(int i = 0;i<vec[1].size();i++)
        Q.push(mp(vec[1][i].first,mp(1,vec[1][i].second)));
    while(vizited>0 && !Q.empty())
    {
        while(viz[Q.top().second.first] && viz[Q.top().second.second] && !Q.empty())
            Q.pop();
        if(Q.empty()) break;
        int n1 = Q.top().second.first;
        int n2 = Q.top().second.second;
        ans.push_back(mp(n1,n2));
        sum+=Q.top().first;
        if(!viz[n1]) vizited--;
        if(!viz[n2]) vizited--;
        Q.pop();
        if(!viz[n1])
            for(int i = 0;i<vec[n1].size();i++)
                if(!viz[vec[n1][i].second]) Q.push(mp(vec[n1][i].first,mp(vec[n1][i].second,n1)));
        if(!viz[n2])
            for(int i = 0;i<vec[n2].size();i++)
                if(!viz[vec[n2][i].second]) Q.push(mp(vec[n2][i].first,mp(vec[n2][i].second,n2)));
        viz[n1] = 1;
        viz[n2] = 1;
    }
}

int32_t main(){_
    //freopen("input","r",stdin);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
		cin >> x >> y;
		s.insert(mp(x,y));
    }
    int i = 1;
    for(auto it : s)
    {
		v.pb(mp(it.first,i));
		vv.pb(mp(it.second,i));
		i++;
	}
	sort(v.begin(),v.end());
	sort(vv.begin(),vv.end());
	n = sz(s);
	vizited = n;
	for(int i = 0;i < sz(v) - 1;i++)
	{
        vec[v[i].second].pb(mp(abs(v[i + 1].first - v[i].first),v[i + 1].second));
        vec[v[i + 1].second].pb(mp(abs(v[i + 1].first - v[i].first),v[i].second));
        m += 2;
	}
	swap(v,vv);
	for(int i = 0;i < sz(v) - 1;i++)
	{
        vec[v[i].second].pb(mp(abs(v[i + 1].first - v[i].first),v[i + 1].second));
        vec[v[i + 1].second].pb(mp(abs(v[i + 1].first - v[i].first),v[i].second));
        m += 2;
	}
	prim();
	rc(sum);
}
