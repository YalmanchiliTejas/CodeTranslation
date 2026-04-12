/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?
//https://github.com/flash7even/Programming-Contest/blob/master/Code%20Repository/Dynamic%20Programming/Digit%20DP/Digit-DP.cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> num;
int a, b, d, k;
int DP[120][120][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

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
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}


signed main () {

    string s;
    cin >> s;
    cin >> k;
    k = s.size()-k;
    for(int i=0;i<s.size();i++){
      num.push_back(s[i]%48);
    }
    // cin >> a >> b >> d >> k;
    d = 0;
    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    // int res = call(0,0,0);
    if(k==1)res--;
    cout << res << endl;

    return 0;
}