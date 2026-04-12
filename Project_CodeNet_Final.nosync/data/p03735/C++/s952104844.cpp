#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}
 
using i64=int64_t;

 
void solve(){
    int N;
    cin >> N;
    vector<i64> x(N),y(N);
    rep(i,0,N){
        cin >> x[i] >> y[i];
        if(x[i]>y[i]) swap(x[i],y[i]);
    }
 
    int min_index=min_element(x.begin(),x.end())-x.begin(),max_index=max_element(y.begin(),y.end())-y.begin();
    if(min_index==max_index){
        i64 l1=x[min_index],r2=y[max_index];
        i64 r1=l1,l2=r2;
        rep(i,0,N){
            r1=max(r1,x[i]);
            l2=min(l2,y[i]);
        }
        cout << (r1-l1)*(r2-l2) << endl;
        return;
    }
 
    i64 ans1,ans2;
    {
        i64 l1=x[min_index],r1=x[max_index],l2=y[min_index],r2=y[max_index];
        rep(i,0,N){
            r1=max(r1,x[i]);
            l2=min(l2,y[i]);
        }
        ans1=(r1-l1)*(r2-l2);
    }
    {
        i64 l1=x[min_index],r1=y[max_index];
        set<pair<i64,i64>> cur,pre;
        pre.insert(make_pair(min(y[min_index],x[max_index]),max(y[min_index],x[max_index])));
        rep(i,1,N){
            for(auto &p:pre){
                int l2=p.first,r2=p.second;
                 int x_=x[i],y_=y[i];
                 if(l2<=x_ and x_<=r2){
                     cur.insert(make_pair(l2,r2));
                     continue;
                 }
                if(l2<=y_ and y_<=r2){
                    cur.insert(make_pair(l2,r2));
                        continue;
                 }
                if(y_<=l2){
                    cur.insert(make_pair(y_,r2));
                        continue;
                 }
                if(r2<=x_){
                    cur.insert(make_pair(l2,x_));
                        continue;
                 }
                cur.insert(make_pair(min(l2,x_),max(r2,x_)));
                cur.insert(make_pair(min(l2,y_),max(r2,y_)));
            }
            pre.clear();
            swap(cur,pre);
        }
        i64 ma=inf64;
        for(auto &p:pre) ma=min(ma,p.second-p.first);
        ans2=(r1-l1)*ma;
    }
    cout << min(ans1,ans2) << endl;
}
 
int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}