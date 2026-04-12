#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define DIVCEIL(A,B) ((A+(B-1))/B)
using namespace std;

void solve(long long n, std::vector<std::string> S){
    vector<map<char, long long>> cnts(n);
    
    set<char> cs;
    for(int i=0; i<n; i++)for(auto c:S[i]){
        cnts[i][c]++;
        cs.insert(c);
    }

    vector<string> ans;
    for(auto c: cs){
        auto nrep = (*min_element(cnts.begin(), cnts.end(), [c](auto cnt1, auto cnt2){return cnt1[c] < cnt2[c];}))[c];
        if(nrep>0)ans.emplace_back(string(nrep, c));
    }

    for(auto s:ans)cout << s;
    cout << endl;
}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<std::string> S(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> S[i];
    }
    solve(n, std::move(S));
    return 0;
}
