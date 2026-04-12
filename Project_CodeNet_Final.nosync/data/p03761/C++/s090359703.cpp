#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define sorta(V) sort(V.begin(), V.end())
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 

using namespace std;

int main(){

    //各文字列の中に出現するアルファベットの回数を記録する
    //全文字列で出現回数が最小値になるものが答えとなる文字列に使える回数になる
    //O(N*|S|)

    int n;
    cin >> n;

    int count[50][26] = {};

    rep(i,n){
        string s;
        cin >> s;

        rep(j,s.size()){
            count[i][s[j] - 'a']++;
        }
    }

    string ans;

    rep(i,26){
        
        int c = INT_MAX;

        rep(j,n){
            c = min(c,count[j][i]);
        }

        string str(c, 'a' + i);

        ans = ans + str;
    }

    cout << ans << endl;


    return 0;
}