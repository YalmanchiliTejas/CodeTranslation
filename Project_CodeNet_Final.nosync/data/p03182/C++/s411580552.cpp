# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include <bits/stdc++.h>
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define rcg(s) cout << s;exit(0)
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define int ll
using namespace std;
int gcd(int a, int b)
{
    if(b) return gcd(b,a%b);
    return a;
}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a[1 << 18],t[1 << 21],lz[1 << 21];
vector<pair<int,int>>vec[1 << 18];
int ans;

void push(int nod)
{
	t[nod] += lz[nod];
	lz[nod << 1] += lz[nod];
	lz[nod << 1 | 1] += lz[nod];
	lz[nod] = 0;	
}

void upd(int nod,int tl,int tr,int l,int r,int val)
{
	if(l > r) return ;
	push(nod);
	if(tl == l && tr == r)
	{
		lz[nod] += val;
		push(nod);
		return ;
	}
	int mid = tl + tr >> 1;
	upd(nod << 1,tl,mid,l,min(mid,r),val);
	upd(nod << 1 | 1,mid + 1,tr,max(mid + 1,l),r,val);
	t[nod] = max(t[nod << 1] + lz[nod << 1],t[nod << 1 | 1] + lz[nod << 1 | 1]);
}

void upd2(int nod,int l,int r,int pos,int val)
{
	if(l == r){
		t[nod] = val;
		return ;
	}
	int mid = l + r >> 1;
	if(pos <= mid){
		upd2(nod << 1,l,mid,pos,val);
	}
	else upd2(nod << 1 | 1,mid + 1,r,pos,val);
	t[nod] = max(t[nod << 1],t[nod << 1 | 1]);
}

int qry(int nod,int tl,int tr,int l,int r)
{
	if(l > r) return -1e18;
	push(nod);
	if(l == tl && r == tr) return t[nod];
	int mid = tl + tr >> 1;
	return max(qry(nod << 1,tl,mid,l,min(mid,r)),
	qry(nod << 1 | 1,mid + 1,tr,max(mid + 1,l),r));
}

int32_t main(){_
    //freopen("in","r",stdin);
	cin >> n >> m;
	for(int i = 1;i <= 4 * n;i++) t[i] = -1e18;
	while(m--)
	{
		int x,y,z;
		cin >> x >> y >> z;
		a[x] += z;
		a[y + 1] -= z;
		vec[y + 1].pb(mp(x,z));
	}
	for(int i = 1;i <= n;i++)
	{
		a[i] += a[i - 1];
		for(auto it : vec[i])
		{
			upd(1,1,n,it.first,i - 1,it.second);
		}
		upd2(1,1,n,i,0);
		int x = a[i] + qry(1,1,n,1,i);
		ans = max(ans,x);
		upd2(1,1,n,i,x - a[i]);
	}
	rc(ans);
}