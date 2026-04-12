#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    string S;
    cin >> N;
    cin >> S;

    vector<vector<char>>  A(4, vector<char>(N,'f'));

    if(S[0] == 'o'){
        A[0][0] = 'S';
        A[0][1] = 'S';
        A[0][N-1] = 'S';

        A[1][0] = 'S';
        A[1][1] = 'W';
        A[1][N-1] = 'W';

        A[2][0] = 'W';
        A[2][1] = 'S';
        A[2][N-1] = 'W';

        A[3][0] = 'W';
        A[3][1] = 'W';
        A[3][N-1] = 'S';
    }
    if(S[0] == 'x'){
        A[0][0] = 'S';
        A[0][1] = 'S';
        A[0][N-1] = 'W';

        A[1][0] = 'S';
        A[1][1] = 'W';
        A[1][N-1] = 'S';

        A[2][0] = 'W';
        A[2][1] = 'S';
        A[2][N-1] = 'S';

        A[3][0] = 'W';
        A[3][1] = 'W';
        A[3][N-1] = 'W';
    }
    REP(i, 4){
        ll flag = true;
        for(ll j=1; j<N; j++){
            if(S[j] == 'o'){
                if(A[i][j] == 'S'){
                    if(A[i][j-1] == 'S'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'S';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'S'){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(A[i][j-1] == 'W'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'W';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'W'){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if(A[i][j] == 'W'){
                    if(A[i][j-1] == 'S'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'W';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'W'){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(A[i][j-1] == 'W'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'S';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'S'){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }
            if(S[j] == 'x'){
                if(A[i][j] == 'S'){
                    if(A[i][j-1] == 'S'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'W';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'W'){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(A[i][j-1] == 'W'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'S';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'S'){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if(A[i][j] == 'W'){
                    if(A[i][j-1] == 'S'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'S';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'S'){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(A[i][j-1] == 'W'){
                        if(A[i][(j+1)%N] == 'f'){
                            A[i][(j+1)%N] = 'W';
                        }
                        else{
                            if(A[i][(j+1)%N] != 'W'){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(flag){
            REP(j, N){
                cout << A[i][j];
            }
            cout << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}