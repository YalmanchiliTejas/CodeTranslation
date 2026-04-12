#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int d;
    cin >> d;
    if(d == -1) exit(0);
    return d;
}

int main(){
    int N, S, T;
    cin >> N >> S >> T;
    int D = ask(S, T);

    vector<pair<int, int>> cand;

    for(int i=1; i<=N; i++) if(S != i && T != i){
        int d1 = ask(i, S);
        int d2 = ask(i, T);
        if(d1+d2 == D) cand.emplace_back(d1, i);
    }

    sort(cand.begin(), cand.end());

    int ld = 0;
    vector<int> ans = {S};
    for(auto& p : cand){
        int b = ans.back();
        int i = p.second;
        int d1 = ask(b, i);
        int d2 = ask(i, T);
        if(ld + d1 + d2 == D){
            ld = p.first;
            ans.push_back(i);
        }
    }
    ans.push_back(T);

    cout << "!";
    for(int a : ans) cout << " " << a;
    cout << endl;

    return 0;
}

