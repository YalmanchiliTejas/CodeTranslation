#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(void){
    string N;
    cin >> N;
    int L = N.size();
    vector<int> d(3, 0),l(3, 0);
    int K;
    cin >> K;
    int cnt = 0;
    for(int i = 0; i < L; i++){
        if(N.at(i) != '0'){
            d.at(cnt) = (int)(N.at(i) - '0');
            l.at(cnt) = L - i;
            cnt++;
        }
        if(cnt == 3){
            break;
        }
    }
    ll ans = 0;
    ll tmp;
    int D,d1,d2,l1,l2; D = d.at(0); d1 = d.at(1); d2 = d.at(2); l1 = l.at(1); l2 = l.at(2);
    if(K == 3){
        for(int i = 3; i <= L - 1; i++){
            ans += 9*9*9 * (i-1) * (i-2) /2; 
        }
        ans += 9*9 * (L-1) * (L-2) * (D-1)/2;
        if(d1 != 0){
            ans += (l1 - 1) * 9 * (d1 - 1);
            ans += 9*9* (l1 - 1) * (l1 - 2) / 2;
        }
        if(d2 != 0){
            ans += d2-1;
            ans += (l2-1)*9;
            ans += 1;
        }
    }
    else if(K == 2){
        for(int i = 2; i <= L - 1; i++){
            ans += 9*9 * (i-1); 
        }        
        ans += (L-1)* 9 * (D-1);
        if(d1 != 0){
            ans += d1-1;
            ans += (l1-1)*9;
            ans += 1;
        }
    }
    else{
        for(int i = 1; i <= L - 1; i++){
            ans += 9; 
        }    
        ans += D;
    }
    printf("%lld\n", ans);
}


