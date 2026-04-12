#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
    int h,w; cin>>h>>w;
    char A[h][w];
    int cnt = 0;
    rep(i,h){
        rep(j,w){
            cin>>A[i][j];
            if(A[i][j] == '#') cnt++;
        }
    }
    int count = 1,i = 0,j = 0;
   // cout<<"cnt=="<<cnt<<endl;
while(1){
while(j<w&&A[i][j+1] == '#'){
    j++;
    count++;
    //cout<<"count=="<<count<<endl;
}
if(i == h-1 && j == w-1 && count == cnt){
    cout<<"Possible"<<endl;
    return 0;
}else if(A[i+1][j] == '#'){
    i++;
    count++;
}else
{
    cout<<"Impossible"<<endl;
    return 0;
}

}
    return 0;
}
