#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int MAX_N = 362881;

// 重複があってもすべての順列を列挙する
// next_permutationは辞書順で次の順列を生成する
int perm[MAX_N];
vector<vector<bool> > p(8, vector<bool>(8));
vector<vector<bool> > used(8, vector<bool>(8));
int answer = 0;
void permutation(int n) {
    rep(i, n){
        perm[i] = i;
    }
    do {
        // permに対する操作
        if(perm[0] != 0) return;
        rep(i, n)
            rep(j, n) used.at(i).at(j) = false;
        rep(i, n){
            if(i == n-1) {
                answer++;
                break;
            }
            if(p.at(perm[i]).at(perm[i+1]) && !used.at(perm[i]).at(perm[i+1])) {
                used.at(perm[i]).at(perm[i+1]) = true;
                used.at(perm[i+1]).at(perm[i]) = true;
            }
            else break;
        }
    } while (next_permutation(perm, perm + n));
    return;
    
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n)
        rep(j, n) p.at(i).at(j) = false;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        p.at(a-1).at(b-1) = true;
        p.at(b-1).at(a-1) = true;
    }
    permutation(n);
    cout << answer << endl;
}