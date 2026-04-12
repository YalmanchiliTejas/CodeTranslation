#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


int N;
ll A[101];

ll ceil_l(ll a, ll b){
    return (a + b - 1) / b;
}

ll fin(){

    ll step = 0;
    while(1){
        {
            ll max_v = -1;
            for(int i = 0; i < N; i++){
                max_v = max(max_v, A[i] );
            }
            if(max_v < N){
                return step;
            }
        }

        int max_idx= -1;
        for(int i = 0; i < N; i++){
            if(A[max_idx] <= A[i]){
                max_idx = i;
            }
        }
        for(int i = 0; i < N; i++){
            if(i == max_idx){
                A[i] -= N;
            }
            else{
                A[i]++;
            }
        }
        step++;
    }
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        // cout << A[i] << endl;
    }


    {
        ll max_v = -1;
        for(int i = 0; i < N; i++){
            max_v = max(max_v, A[i]);
        }
        if(max_v <= N - 1){
            cout << 0 << endl;
            return 0;
        }
    }

    ll step = 0;
    while(1){
        sort(A, A + N, greater<ll>());

        if(A[0] <= 2 * N){
            step += fin();
            cout << step << endl;
            return 0;
        }


        // 一番大きい要素からN以内の要素はひとまとめにして扱う
        int less_than_n_index = 0;
        int less_than_n_count = 0;
        for(int i = 1; i < N; i++){
            if(abs(A[0] - N) <= A[i]){
                less_than_n_index = i;
                less_than_n_count++;
            }
        }

        // 最後までいったのであれば、終了
        if(less_than_n_index == N - 1){
            ll min_v = 1LL<<60;
            for(int i = 0; i < N; i++)
                min_v = min(min_v, A[i]);

            ll d = max(0LL, min_v - N);

            step += d * N;
            for(int i = 0; i < N; i++){
                A[i] -= d;
            }

            cout << step + fin() << endl;
            return 0;
        }
        
        // 次の要素との差がN以下、または最大値がN以上となる最小の場所まで移動する
        ll next = A[less_than_n_index + 1];
        
        //  (A[0] - (N - less_than_n_count) * i) -  (next + i) <= N
        //  (N - less_than_n_count + 1) * i)  >= -N - next + A[0]
        // i >= (A[0] - N - next) / (N - less_than_n_count + 1)
        ll j = ceil_l(A[0] - N - next, N - less_than_n_count + 1);
        if(A[0] - (N - less_than_n_count) * j <= N){
            j--;
        }

        for(int i = 0; i < N; i++){
            if(i <= less_than_n_index){
                A[i] -= (N - less_than_n_count) * j;
            }
            else{
                A[i] += j * (less_than_n_count + 1);
            }
        }

        // sort(A, A + N, greater<int>());
        // for(int i = 0; i < N; i++){
        //     cout << A[i] << " ";
        // }
        // cout << endl;

        // cout << j << " " << less_than_n_count + 1 <<  endl;

        step += j * (1 + less_than_n_count);

    }

    return 0;
}

