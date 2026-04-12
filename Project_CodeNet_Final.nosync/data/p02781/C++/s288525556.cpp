#include <bits/stdc++.h>
using namespace std;

vector<char> num;
int a, b, d, k;
int DP[200][12][2];

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;
    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
       
        LMT = num[pos] - '0';
    } else {
        LMT = 9;
    }

    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; 
        if(dgt != d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(string b){
    num.clear();
    for(auto x : b){
      num.push_back(x);
    }
    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {
    string b; cin >> b;
    cin >> k;
    d = 0;
    int res = solve(b) ;
    cout << res << endl;

    return 0;
}