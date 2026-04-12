#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> a0(n+1), a1(n+1), a2(n+1), a3(n+1);
    std::reference_wrapper<vector<bool>> answers[] = {a0, a1, a2, a3};

    const bool S = false;
    const bool W = true;
    // init
    answers[0].get()[0] = S;
    answers[1].get()[0] = S;
    answers[2].get()[0] = W;
    answers[3].get()[0] = W;
    answers[0].get()[1] = S;
    answers[1].get()[1] = W;
    answers[2].get()[1] = S;
    answers[3].get()[1] = W;
    
    for(int i = 1; i < n; ++i){
        const bool said_same = s[i] == 'o';
        for(auto&& ar : answers){
            auto& a = ar.get();
            const bool should_same = (said_same && a[i] == S) || (!said_same && a[i] == W);
            const bool next = (should_same ? a[i-1] : !a[i-1]);
            a[i+1] = next;
        }
    }
    {
        // check
        const bool said_same = s[0] == 'o';
        for(auto&& ar : answers){
            auto& a = ar.get();
            const bool should_same = (said_same && a[0] == S) || (!said_same && a[0] == W);
            const bool next = (should_same ? a[n-1] : !a[n-1]);
            if(a[0] == a[n] && a[1] == next){
                for(int i = 0; i < n; ++i){
                    cout << (a[i] == S ? 'S' : 'W');
                }
                cout << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
        return 0;
    }
}
