#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;


string s;
int K;
vector<int>f(1e4+1);
vector<vector<int>>eq(1e4+1,vector<int>(1e2+3,0));
vector<vector<int>>lt(1e4+1,vector<int>(1e2+3,0));

int mod(int a,int b){
    a %= b;
    if(a < 0) a += b;
    return a;
}

int mod(int a){
    return mod(a,MOD);
}


signed main(void){
    cin >> s >> K;
    for(int i=0;i<s.length();i++) f[i] = s[i] - '0';
    // １番目のけたを見て，eqとltを更新
    for(int i=0;i<=9;i++){
        if(f[0]==i) eq[0][mod(i,K)] += 1;
        if(i < f[0]) lt[0][mod(i,K)] += 1;
    }

    // i番目のけたを見てとりうる値（k）を考える，足してjになるような個数をカウント
    for(int i=1;i<s.size();i++){
        for(int j=0;j<K;j++){
            // cout << i << ' ' << j << ' ' << f[i]-j << ' ' << K << ' ' <<mod(f[i]-j,K) << endl;;
            eq[i][j] = eq[i-1][mod(j-f[i],K)];
            for(int k=0;k<=9;k++){
                // cout << mod(j-k,K) << endl;
                lt[i][j] = mod(lt[i][j]+lt[i-1][mod(j-k,K)],MOD);
            }
            for(int k=0;k<f[i];k++){
                lt[i][j] = mod(lt[i][j]+eq[i-1][mod(j-k,K)],MOD);
            }
        }
    }

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<10;j++){
    //         cout << lt[i][j] << ' ';
    //     }cout << endl;
    // }

    // lt[s.size()-1][0]，eq[s.size()-1][0]:最後の桁まで見て総和がdの倍数となる個数．ただし０がカウントされているので−１する
    cout << mod(lt[s.size()-1][0] + eq[s.size()-1][0] - 1,MOD) << endl;;
    return 0;
}