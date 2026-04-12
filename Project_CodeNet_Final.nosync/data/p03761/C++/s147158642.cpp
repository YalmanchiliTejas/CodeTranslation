#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define DIVCEIL(A,B) ((A+(B-1))/B)
using namespace std;

void solve(long long n, std::vector<std::string> S){
    vector<map<char, long long>> cnts(n);
    for(int i=0; i<n; i++)for(auto c:S[i])cnts[i][c]++;

    vector<char> ans;
    auto s = S[0];
    sort(s.begin(), s.end());
    for(auto c:s){
        if(all_of(cnts.begin(), cnts.end(), [c](auto cnt){
            return cnt.find(c) != cnt.end() && cnt[c]>0;
        })){
            for(auto &cnt:cnts)cnt[c]--;
            ans.push_back(c);
        }
    }
    for(auto c:ans)cout << c;
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
