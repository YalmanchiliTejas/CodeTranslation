#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

template <typename T>
class SegmentTree{
    public:
        ll size;
        vector<T> node;
        T identity_ele;  //comp(x, identity_ele) == x
        function<T(T, T)> comp;

        SegmentTree(const vector<T> &v, function<T(T, T)> comp, T identity_ele){
            ll tmp = 1;
            while(tmp < v.size()) tmp = (tmp << 1);
            this->size = tmp;
            this->identity_ele = identity_ele;
            this->comp = comp;
            node.resize(2 * size - 1);
            for(ll i = 0; i < v.size(); i++){
                node[i + size - 1] = v[i];
            }
            for(ll i = size - 2; 0 <= i; i--){
                node[i] = comp(node[i * 2 + 1], node[i * 2 + 2]);
            }
        }

        void update(ll pos, T value){
            pos += size - 1;
            node[pos] = value;
            while(pos > 0){
                pos = (pos - 1) / 2;
                node[pos] = comp(node[2 * pos + 1], node[2 * pos + 2]);
            }
        }

        T query(ll a, ll b){
            return subQuery(a, b, 0, 0, size);
        }

        T subQuery(ll a, ll b, ll k, ll l, ll r){
            if(r <= a || b <= l){
                return identity_ele;
            }else if(a <= l && r <= b){
                return node[k];
            }else{
                T left = subQuery(a, b, k * 2 + 1, l, (l + r) / 2);
                T right = subQuery(a, b, k * 2 + 2, (l + r) / 2, r);
                return comp(left, right);
            }
        }
};

ll N;
vector<P> balls;
vector<P> bags;
const ll INF = 5e15;

ll check1(){
    ll rmax, rmaxb ,rmin, rminb;
    tie(rmax, rmaxb) = balls[balls.size() - 1];
    for(ll i = 0; i < balls.size(); i++){
        if(balls[i].second != rmaxb){
            tie(rmin, rminb) = balls[i];
            break;
        }
    }
    vector<P> blues;
    vector<ll> values;
    for(ll i = 0; i < N; i++){
        if(i == rminb){
            blues.push_back(P(bags[i].second, i));
            values.push_back(bags[i].second);
        }else{
            blues.push_back(P(bags[i].first, i));
            values.push_back(bags[i].first);
        }
    }
    sort(blues.begin(), blues.end());
    SegmentTree<ll> ST(values, [](ll a, ll b){ return min(a, b); }, INF);
    ll bmax = blues[N - 1].first;
    ll bmaxmin = blues[N - 1].first - blues[0].first;
    for(ll i = 0; i < N; i++){
        ll idx = blues[i].second;
        if(idx == rmaxb || idx == rminb) continue;
        bmax = max(bmax, bags[idx].second);
        ST.update(idx, bags[idx].second);
        ll bmin = ST.query(0, N);
        bmaxmin = min(bmaxmin, bmax - bmin);
    }
    return (rmax - rmin) * bmaxmin;
}

ll check2(){
    ll rmax, rmaxb, bmin, bminb;
    tie(rmax, rmaxb) = balls[balls.size() - 1];
    tie(bmin, bminb) = balls[0];
    ll bmax = 0, rmin = INF;
    for(ll i = 0; i < N; i++){
        if(i == rmaxb && i == bminb){
            continue;
        }else if(i == rmaxb){
            bmax = max(bmax, bags[i].first);
        }else if(i == bminb){
            rmin = min(rmin, bags[i].second);
        }else{
            bmax = max(bmax, bags[i].first);
            rmin = min(rmin, bags[i].second);
        }
    }
    return (rmax - rmin) * (bmax - bmin);
}

int main(){
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        balls.push_back(P(x, i));
        balls.push_back(P(y, i));
        bags.push_back(P(x, y));
    }
    if(N == 1){
        cout << 0 << endl;
        return 0;
    }
    sort(balls.begin(), balls.end());
    cout << min(check1(), check2()) << endl;
    return 0;
}
