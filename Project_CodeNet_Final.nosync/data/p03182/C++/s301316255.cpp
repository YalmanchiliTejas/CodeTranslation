#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
const ll INF = 5e15;
const ll MOD = 1e9 + 7;

/*
 * This LazySegmentTree is tree for query "ADD".
 * If you want to change query, you have to change the function "eval".
 * Too show where you have to change, I wrote the comment "!! TO CHANGE !!".
 */

class LazySegmentTree {
    private:
        ll N, init;
        vector<ll> node, lazy;
        vector<bool> lazy_flag;
    
    public:
        LazySegmentTree(const vector<ll> &v, ll init){
            this->init = init;
            ll tmp = 1;
            while(tmp < v.size()) tmp *= 2;
            N = tmp;
            node.resize(2 * N - 1);
            lazy.resize(2 * N - 1, init);
            lazy_flag.resize(2 * N - 1, init);
            for(ll i = 0; i < v.size(); i++){
                node[i + N - 1] = v[i];
            }
            for(ll i = N - 2; 0 <= i; i--){

                /*
                 * !! TO CHANGE !!
                 * You have to change the operator '+' between node[i * 2 + 1] and node[i * 2 + 2]
                 */
                node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
            }
        }

        /*
         * node[pos] -> [left, right)
         */
        void lazy_eval(ll pos, ll left, ll right){
            if(!lazy_flag[pos]){
                return;
            }

            /*
             * !! TO CHANGE !!
             * How to update the value node[pos] by using lazy[pos]
             */
            node[pos] += lazy[pos];
            lazy_flag[pos] = false;

            /* 
             * whether the node is the bottom of tree or not.
             */
            if(right - left > 1){

                /*
                 * !! TO CHANGE !!
                 * How to propagate the value to under node.
                 * For example, when the query is "ADD", you have to add half of value to under node.
                 */
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
                lazy_flag[2 * pos + 1] = true;
                lazy_flag[2 * pos + 2] = true;
            }
            
            /*
             * !! TO CHANGE !!
             * Init lazy[pos] because it alredy has been evaluated.
             */
            lazy[pos] = init;
        }

        /*
         * If you want to call this func from out of class, in many cases you don't have to change the args pos, node_left, node_right.
         * Be careful that the range is half-open interval.
         * [left, right), [node_left, node_right)
         * @param left:         lower limit of interval of query
         * @param right:        upper limit of interval of query
         * @param val:          the value gave from query
         * @param node_left:    lower limit of interval of the node points.
         * @param node_right:   upper limit of interval of the node points.
         */
        void update_query(ll left, ll right, ll val, ll pos = 0, ll node_left = 0, ll node_right = -1){
            if(node_right < 0){
                node_right = N;
            }

            /*
             * Execute lazy evaluation.
             */
            lazy_eval(pos, node_left, node_right);

            /*
             * If the node is out of inrerval, return.
             */
            if(right <= node_left || node_right <= left){
                return;
            }


            /*
             * If the node cover the interval complety, update this->lazy and execute lazy_eval.
             * Else recursion.
             */
            if(left <= node_left && node_right <= right){

                /*
                 * !! TO CHANGE !!
                 * How to propagate the val and how to summary the val..
                 */
                lazy[pos] += val;
                lazy_flag[pos] = true;
                lazy_eval(pos, node_left, node_right);
            }else{

                /*
                 * recursion
                 */
                update_query(left, right, val, 2 * pos + 1, node_left, (node_left + node_right) / 2);
                update_query(left, right, val, 2 * pos + 2, (node_left + node_right) / 2, node_right);
                
                /*
                 * !! TO CHANGE !!
                 * How to summary the value under the node.
                 */
                node[pos] = max(node[2 * pos + 1], node[2 * pos + 2]);
            }
        }

        ll get_query(ll left, ll right, ll pos = 0, ll node_left = 0, ll node_right = -1){
            if(node_right < 0){
                node_right = N;
            }

            /*
             * Evaluate the node[pos]
             */
            lazy_eval(pos, node_left, node_right);

            if(node_right <= left || right <= node_left){
                return -INF;
            }
            if(left <= node_left && node_right <= right){
                return node[pos];
            }

            /*
             * !! TO CHANGE !!
             * You have to change the mark '+' between get_query and get_query.
             */
            return max(get_query(left, right, 2 * pos + 1, node_left, (node_left + node_right) / 2), 
                       get_query(left, right, 2 * pos + 2, (node_left + node_right) / 2, node_right));
        }
};

int main(){
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    LazySegmentTree LST(vector<ll>(N + 10), 0);
    vector<ll> left(2 * 1e5 + 10, 0);
    map<ll, vector<P>> right;
    for(ll i = 0; i < M; i++){
        ll l, r, a;
        cin >> l >> r >> a;
        left[l] += a;
        right[r].push_back(P(l, a));
    }
    for(ll i = 1; i <= N; i++){
        LST.update_query(0, i, left[i]);
        ll val = LST.get_query(0, i);
        ans = max(ans, val);
        LST.update_query(i, i + 1, val);
        const auto &vec = right[i];
        for(const auto &p : vec){
            LST.update_query(0, p.first, -p.second);
        }
    }
    cout << ans << endl;
    return 0;
}

