#include<bits/stdc++.h>
using ll  = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define erep(e,v) for(auto && e :v)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){for(auto itr :a){if(itr != *a.begin())cout << " "; cout << itr;} }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
deque<int>line;
ll maxim(){
    auto val = line.front();
    line.pop_front();
    return val;
}
ll minimum(){
    auto val = line.back();
    line.pop_back();
    return val;
}
signed main(){
    int n; cin >> n;
    if(n == 2){
        int a,b;cin>>a>>b;
        return cout << abs(a-b) << endl,0;
    }
    vector<int>v(n);
    erep(e,v) cin >> e;
    sort(all(v),greater<int>());
    int fans = 0;
    rep(_,2){
        rep(i,n)line.push_back(v[i]);
        deque<int>deq;
        bool rising = _%2;
        while(!line.empty()){
            if(deq.empty()){
                deq.push_front( (rising ? maxim() :minimum()) );
                deq.push_front( (rising ? minimum() :maxim()) );
                deq.push_back( (rising ? minimum() :maxim())  );
                
            }else {
                if(line.size() >= 2){
                    int a = (rising ? minimum(): maxim());
                    int b = (rising ? minimum(): maxim());
                    if(abs(deq.front() - a) + abs(deq.back() - b) >
                       abs(deq.front() - b) + abs(deq.back() - a) ) {
                        deq.push_front(a);
                        deq.push_back(b);
                    } else {
                        deq.push_front(b);
                        deq.push_back(a);
                    }
                } else {
                    int val = (rising ? minimum():maxim());
                    if(abs(deq.front() - val) > abs(deq.back() - val)){
                        deq.push_front(val);
                    } else {
                        deq.push_back(val);
                    }
                }
            }
            rising = !rising;
        }
        int ans = 0;
  //      join(deq); cout << endl;
        int top = deq.front();
        deq.pop_front();
        while(deq.size()){
            ans += abs(top - deq.front());
            top = deq.front();
            deq.pop_front();
        }
        cmax(fans, ans);
    }
    cout << fans << endl;
}



