#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M){
        cin >> a.at(i) >> b.at(i);
    }
    auto check = [&](int _a, int _b) {
        rep(j, M)
        {
            if(a.at(j) == _a && b.at(j) == _b)
            {
                return true;
            }
            else if(a.at(j) == _b && b.at(j) == _a)
            {
                return true;
            }
        }
        return false;
    };

    vector<int> num(N-1);
    iota(num.begin(), num.end(), 2);
    int count = 0;
    do{
        bool c = true;
        vector<int> num2(N - 1);
        num2 = num;
        auto it = num2.begin();
        num2.insert(it, 1);
        rep(i, N-1){
            if(!check(num2.at(i), num2.at(i+1))){
                c = false;
            }
        }
        if(c){
            count++;
        }
    } while (next_permutation(num.begin(), num.end()));

    cout << count << endl;
}