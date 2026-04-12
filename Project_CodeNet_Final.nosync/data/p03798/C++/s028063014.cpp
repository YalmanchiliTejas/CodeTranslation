#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int N;
string S;

vector<int> check(int s0, int s1){
    int P[N];
    fill(P, P+N, -1);
    bool fl = true;
    P[0] = s0;
    P[1] = s1;

    vector<int> ret;

    // 0:S, 1:W
    for(int i=0; i<N; i++){
        int b = (N+i-1)%N;
        int a = (i+1)%N;
        if(P[b] == -1) swap(a, b);

        if(P[a] != -1 && P[b] != -1){
            if(S[i] == 'o' && P[i] == 0 && P[b] != P[a]) fl = false;
            if(S[i] == 'o' && P[i] == 1 && P[b] == P[a]) fl = false;
            if(S[i] == 'x' && P[i] == 0 && P[b] == P[a]) fl = false;
            if(S[i] == 'x' && P[i] == 1 && P[b] != P[a]) fl = false;
        }
        if(!fl) break;

        if(S[i] == 'o' && P[i] == 0){
            P[a] = P[b];
        }
        if(S[i] == 'o' && P[i] == 1){
            P[a] = !P[b];
        }
        if(S[i] == 'x' && P[i] == 0){
            P[a] = !P[b];
        }
        if(S[i] == 'x' && P[i] == 1){
            P[a] = P[b];
        }
        ret.push_back(P[i]);
    }

    vector<int> emp;
    if(!fl) return emp;
    else return ret;
}

int main(){
    cin >> N;
    cin >> S;

    vector<int> ans;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            vector<int> t = check(i, j);
            if(!t.empty()){
                ans = t;
            }
        }
    }

    if(ans.empty()){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<N; i++){
        if(ans[i] == 0) cout << "S";
        else cout << "W";
    }
    cout << endl;

    return 0;
}
