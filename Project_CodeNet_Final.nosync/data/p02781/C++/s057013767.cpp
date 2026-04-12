#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<ll>> value;

ll factorial(ll n){
    if(n==0) return 1;
    else return n * factorial(n-1);
}

ll calc(ll n, ll r){
    if(value[n][r] != -1) return value[n][r];
    if(n==r || r==0){
        value[n][r] = 1;
    }else{
        value[n][r] = (calc(n-1,r-1) + calc(n-1,r));
    }
    return value[n][r];
}

int main(){
    string N;  cin >> N;
    ll K;  cin >> K;
    ll D = N.length();
    if(D < K){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    value.resize(max(D+1, 10ll), vector<ll>(K+1, -1));
    for(int i=K; i<D; i++){
        ans += pow(9, K) * calc(i-1, K-1);
    }

    vector<int> flag(D-1, 0);
    for(int i=0; i<K-1; i++){
        flag[D-2-i] = 1;
    }   

    if(N[0] - '0' > 1){
        ans += (N[0]-'0'-1)*pow(9, K-1)*calc(D-1, K-1);
    }
    if(K == 1) ans++;
    else if(K==2){
        do {
            for(int i=1; i<=9; i++){
                string temp = "";
                temp += N[0];
                for(int k=1; k<D; k++){
                    if(flag[k-1] == 1) temp += to_string(i);
                    else temp += "0";
                }
                if(temp <= N) ans++;
            }
        }while(next_permutation(flag.begin(), flag.end()));
    }else if(K==3){
        do {
            for(int i=1; i<=9; i++) for(int j=1; j<=9; j++){
                string temp = "";
                temp += N[0];
                bool first = true;
                for(int k=1; k<D; k++){
                    if(flag[k-1] == 1 && first){
                        temp += to_string(i);
                        first = false;
                    }
                    else if(flag[k-1] == 1) temp += to_string(j);
                    else temp += "0";
                }
                if(temp <= N){
                    ans++;
                }
            }
        }while(next_permutation(flag.begin(), flag.end()));
    }
    cout << ans << endl;
}
