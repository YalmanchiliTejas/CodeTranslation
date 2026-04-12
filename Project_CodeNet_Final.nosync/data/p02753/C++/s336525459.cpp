#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

const string YES = "Yes";
const string NO = "No";

void func(std::string S){
    string ret = YES;
    if (S=="AAA" || S=="BBB") {
        ret = NO;
    }
    cout << ret << endl;
}

int main(){
    // cout << fixed << setprecision(5);

    std::string S;
    std::cin >> S;
    func(S);
    return 0;
}
