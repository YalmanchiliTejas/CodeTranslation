#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

static const int MAX = 1e+5;
enum {W, S};
enum {x, o};
int n;
bool anim[MAX], same[MAX];

bool check(bool a1, bool a2){
    anim[0] = a1, anim[1] = a2;
    for(int i = 1; i < n - 1; i++){
        if(same[i]){
            if(anim[i] == S) anim[i + 1] = anim[i - 1];
            else anim[i + 1] = !anim[i - 1];
        } else {
            if(anim[i] == S) anim[i + 1] = !anim[i - 1];
            else anim[i + 1] = anim[i - 1];
        }
    }
    bool res;
    res = (same[n - 1] == anim[n - 1]) == (anim[n - 2] == anim[0]);
    res = res && (same[0] == anim[0]) == (anim[n - 1] == anim[1]);
    return res;
}

int main(){
    cin >> n;
    char ch;
    rep(i, n){
        cin >> ch;
        same[i] = (ch == 'o' ? o : x);
    }

    if(check(S, S)){
        rep(i, n) cout << (anim[i] == S ? 'S' : 'W');
        cout << endl;
    } else if(check(S, W)){
        rep(i, n) cout << (anim[i] == S ? 'S' : 'W');
        cout << endl;
    } else if(check(W, S)){
        rep(i, n) cout << (anim[i] == S ? 'S' : 'W');
        cout << endl;
    } else if(check(W, W)){
        rep(i, n) cout << (anim[i] == S ? 'S' : 'W');
        cout << endl;
    } else cout << -1 << endl;

    return 0;
}
