#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


/**
 * @brief
 * 範囲加算と範囲最大値を求めるセグツリー
 */
template<class T, int MAX_SIZE>
class range_max_add_tree{
private:
    std::size_t size_;
    T unif_adds_[MAX_SIZE];
    T max_des_[MAX_SIZE];
    const T MIN_INF = numeric_limits<T>::min();
  
public:
    range_max_add_tree(){}

    size_t size()
    {
        return size_;
    }
    void init(size_t size)
    {
        // size_は2の倍数に調整する
        size_ = 1;
        while(size_ < size)
            size_ *= 2;
        for(size_t i=0;i<2*size_-1;i++)
            unif_adds_[i] = max_des_[i] = 0;
    }

    // [a,b)に対して+=vする
    void update(size_t a, size_t b, T v)
    {
        update_impl(a, b, 0, 0, size_, v);
    }
  
    // [a,b)の最大値を求める
    T max(size_t a, size_t b)
    {
        return max_impl(a, b, 0, 0, size_);
    }
  
private:  
    void update_impl(size_t a, size_t b, std::size_t k, size_t l, size_t r, T v)
    {
        // 範囲から外れた場合
        if(r<=a||l>=b)return;
        // 完全に含まれる
        else if(a<=l&&b>=r){
            unif_adds_[k] += v;
            max_des_[k] += v;
        }
        else{
            // この範囲に値を加算しておく
            // それ以外は,クエリを分割
            // max_des_[k] += v;
            update_impl(a, b, k * 2 + 1, l, (l + r) /2, v);
            update_impl(a, b, k * 2 + 2, (l + r) / 2, r, v);
            // std::を付けないとこのクラスのpublicメソッドmax が呼ばれる
            max_des_[k] = std::max(max_des_[k * 2 + 1], max_des_[k * 2 + 2]) + unif_adds_[k];
        }
    }
    T max_impl(size_t a, size_t b, std::size_t k, size_t l, size_t r)
    {
        // 完全に含まれる
        if(a<=l&&b>=r){
            return max_des_[k];
        }
        // 範囲から外れた場合
        else if(r<=a||l>=b) return MIN_INF;
        // それ以外は,クエリを分割
        // std::を付けないとこのクラスのpublicメソッドmax が呼ばれる
        return std::max(max_impl(a, b, k * 2 + 1, l, (l + r) /2), 
                        max_impl(a, b, k * 2 + 2, (l + r) / 2, r)) + unif_adds_[k];
    }
};

range_max_add_tree<ll, 1000000> st;
int N, M;
int L[200010];
int R[200010];
int A[200010];
vector<pii> es[200010];

int main(){    

    cin >> N >> M;
    st.init(N + 2);
    for(int i = 0; i < M; i++){
        cin >> L[i] >> R[i] >> A[i];
    }
    for(int i = 0; i < M; i++){
        es[L[i]].push_back(pii(i, 0));
        es[R[i] + 1].push_back(pii(i, 1));
    }

    /*
      dp[i] = max(dp[m] + sum(A[k]))
      を計算する
      mは最後に1にした場所
      k は m < L[k] <= i <= R[k] を満たすもの
     */
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        for(pii p : es[i]){
            int e_id = p.first;
            int is_out = p.second;
            if(!is_out){
                // in
                st.update(0, i, A[e_id]);
            }
            else{
                // out
                st.update(0, L[e_id], -A[e_id]);
            }
        }
        if(i - 1 >= 0) {
            st.update(i, i + 1, st.max(0, i));
            ans = max(ans, st.max(i, i + 1));
        }
    }
    cout << ans << endl;

    return 0;
}
