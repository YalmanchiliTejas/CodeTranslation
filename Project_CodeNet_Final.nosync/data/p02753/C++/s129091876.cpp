#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
    int cnt = 0;
    for(auto s : S){
        if(s == 'A') cnt++;
    }
    if(cnt > 0 && cnt < 3) cout << YES << endl;
    else cout << NO << endl;
    return;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
