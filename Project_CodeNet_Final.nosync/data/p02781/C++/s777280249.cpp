#include <bits/stdc++.h>

using namespace std;

int solve(string s, int k){
    if(s == "")
        return 0;

    if(k==1){
        return (s.length()- 1) * 9 + (s[0] - '0');
    }

    int ans = 0, len = s.length();
    if(k==2){
        if(len>=3)
            ans += (len-1) * (len-2) / 2 * 81;
        if(len>=2)
            ans += (s[0] - '1') * (len - 1) * 9;
    }
    if(k==3){
        if(len>=4)
            ans += (len-1) * (len-2) * (len-3) / 6 * 729;
        if(len >= 3)
            ans += (s[0] - '1') * (len-1) * (len-2) / 2 * 81;
    }

    int p = 1;
    while(p<len && s[p] == '0'){
        p++;
    }

    ans += solve(s.substr(p), k-1);

    return ans;
}

int main(){
    string s;
    int k, ans = 0;
    cin >>s>>k;

    cout <<solve(s, k);
}
