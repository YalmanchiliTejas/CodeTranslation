#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

template<typename T> class LazyRMQ {
    public:
    int n;
    T inf = INT_MAX;
    vector<T> data, lazy;

    LazyRMQ(int m, T init_value=INT_MAX){
        // 2のべき乗にする
        n = 1;
        while(n < m) n <<= 1;
        data.assign(2*n-1, init_value);
        lazy.assign(2*n-1, 0);
    }

    void eval(int k, int kl, int kr){
        if(data[k] == inf) data[k] = 0;
        if(lazy[k] == 0) return;
        data[k] += lazy[k];
        if(kr - kl > 1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    // [s,t)
    void add(int s, int t, int k, int kl, int kr, T x){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return;
        if(s <= kl && kr <= t){
            lazy[k] += x;
            eval(k, kl, kr);
            return;
        }
        int kc = (kl+kr)/2;
        add(s, t, 2*k+1, kl, kc, x);
        add(s, t, 2*k+2, kc, kr, x);
        data[k] = min(data[2*k+1], data[2*k+2]);
    }

    // [s,t)
    T find(int s, int t, int k, int kl, int kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return inf;
        if(s <= kl && kr <= t) return data[k];
        int kc = (kl+kr)/2;
        T vl = find(s, t, 2*k+1, kl, kc);
        T vr = find(s, t, 2*k+2, kc, kr);
        return min(vl, vr);
    }
};

int main(){
    int n,Q,q;
    scanf("%d %d", &n, &Q);
    LazyRMQ<int> rmq(n+1);

    char s[n+1];
    scanf("%s", s);
    set<int> close;
    int data[n+1];
    data[0] = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            data[i+1] = data[i]+1;
        }else{
            data[i+1] = data[i]-1;
            close.insert(i+1);
        }
        rmq.add(i+1, i+2, 0, 0, rmq.n, data[i+1]);
    }

    for(int i=0;i<Q;i++){
        scanf("%d", &q);
        // 今回の変更により，閉じかっこが開いたか？
        bool open_parentheses = (s[q-1] == ')');
        int j;
        if(open_parentheses){
            rmq.add(q, rmq.n, 0, 0, rmq.n, 2);
            s[q-1] = '(';
            close.erase(q);
            // どこかの開きかっこを閉じる
            // 「以降全て2以上」のところはひっくり返せる
            j = (n+1)/2;
            int ng = 0, ok = n;
            while(ok-ng > 1){
                j = (ng+ok)/2;
                if(rmq.find(j, rmq.n, 0, 0, rmq.n) >= 2){
                    ok = j;
                }else{
                    ng = j;
                }
            }
            j = ok;
            rmq.add(j, rmq.n, 0, 0, rmq.n, -2);
            s[j-1] = ')';
            close.insert(j);
        }else{
            rmq.add(q, rmq.n, 0, 0, rmq.n, -2);
            s[q-1] = ')';
            close.insert(q);
            // どこかの閉じかっこを開く
            // 先頭の閉じかっこをひっくり返せば良い
            j = *close.begin();
            rmq.add(j, rmq.n, 0, 0, rmq.n, 2);
            s[j-1] = '(';
            close.erase(j);
        }
        printf("%d\n", j);
    }
}

