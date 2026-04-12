#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<58;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

void compress(vector<int> &v,map<double,int>& zip){
    vector<double> x;
    rep(i,0,v.size()){
        x.emplace_back(v[i]-0.5);
        x.emplace_back(v[i]);
        x.emplace_back(v[i]+0.5);
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    rep(i,0,x.size()) zip[x[i]]=i;
}

void solve(){
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> l(n),t(n),r(n),b(n);
        rep(i,0,n) cin >> l[i] >> t[i] >> r[i] >> b[i];

        map<double,int> zipx,zipy;
        vector<int> tmpx=l,tmpy=t;
        tmpx.insert(tmpx.end(),r.begin(),r.end());
        tmpy.insert(tmpy.end(),b.begin(),b.end());
        compress(tmpx,zipx);
        compress(tmpy,zipy);

        const int w=zipx.size(),h=zipy.size();
        vector<vector<bool>> field(w,vector<bool>(h,false));
        rep(i,0,n){
            rep(x,zipx[l[i]],zipx[r[i]]+1) field[x][zipy[t[i]]]=field[x][zipy[b[i]]]=true;
            rep(y,zipy[b[i]],zipy[t[i]]+1) field[zipx[l[i]]][y]=field[zipx[r[i]]][y]=true;
        }

        int ans=0;
        rep(x,0,w) rep(y,0,h){
            if(field[x][y]) continue;
            ++ans;
            queue<pii> que;
            que.push(make_pair(x,y));
            field[x][y]=true;
            while(!que.empty()){
                pii p=que.front(); que.pop();
                rep(i,0,4){
                    const int nx=p.first+dx[i],ny=p.second+dy[i];
                    if(nx<0 or w<=nx or ny<0 or h<=ny or field[nx][ny]) continue;
                    que.push(make_pair(nx,ny));
                    field[nx][ny]=true;
                }
            }
        }
        cout << ans << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cout << fixed << setprecision(8);
    solve();
    return 0;
}