#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a,ll b){
	if(b==0)return a;return gcd(b,a%b);
}



ll lt[1234][1234], rt[1234][1234], upper[1234][1234], lower[1234][1234];

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}


int arr[12345678];

int main(){
    //freopen("ip.txt", "rt", stdin);
    //freopen("op.txt", "wt", stdout);

    string s;
    cin >> s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
