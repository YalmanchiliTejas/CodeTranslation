#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef long long int ll;
const int E_MAX = 102;
const int K_MAX = 4;

string n;
int k;

ll Choice(int l, int t){
    if (t < 0)return 0;
    ll ans = 1;
    for(int i = 0; i < t; i++)ans *= (l-i);
    for(int j = 1; j <= t; j++)ans /= j;
    return ans;
}

ll pow(int l, int t){
    ll ans = 1;
    for(int i = 0; i < t; i++)ans *= l;
    return ans;
}

int main(){
    cin >> n >> k;
    int e = n.length();
    ll ans = 0;
    for(int i = k; i >= 0; i--){
        int res = i;
        int now = 0;
        while(res > 0 && now < e){
            if (n[now] != '0')res--;   
            now++;         
        }
        while(n[now] == '0' && now < e)now++;
        if (now == e && res != 0)continue;
        else if (now == e){
            if (i == k)ans++;
            continue;
        }
        int num = n[now] - '0';
        ans += ((ll)num - 1) * Choice(e-1-now, k-i-1) * pow(9, k-i-1) + Choice(e-1-now, k-i) * pow(9, k-i);
    }
    cout << ans << endl;
    return 0;
}