#include <bits/stdc++.h>
using namespace std;

int getN(string N, int K, bool noLimit){
    int n = N.size();
    if(n<K) return 0;
    int m = noLimit? 9 : stoi(N.substr(0, 1));
    if(n==1 && K==1) return m;
    N = N.substr(1);
    int res = 0;
    if(m==0){
        res += getN(N, K, false);
    }else{
        res += getN(N, K, true);
    }
    if(K==1){
        res += m;
    }else{
        if(noLimit){
            res += 9 * getN(N, K-1, true);
        }else{
            if(m>0){
                res += (m-1) * getN(N, K-1, true);
                res += getN(N, K-1, false);
            }
        }
    }
    return res;
}

int main()
{
    string N;
    cin >> N;
    int K;
    cin >> K;
    auto res = getN(N, K, false);
    cout << res << endl;

    return 0;
}