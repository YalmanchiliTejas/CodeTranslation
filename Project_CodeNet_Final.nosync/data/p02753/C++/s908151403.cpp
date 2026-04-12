#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
    if(count(S.begin(), S.end(), 'A') == 3 || count(S.begin(), S.end(), 'B') == 3){
        cout<<NO<<endl;
    }else{
        cout<<YES<<endl;
    }
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
