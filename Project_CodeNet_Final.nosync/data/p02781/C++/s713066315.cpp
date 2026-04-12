#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define MOD 1000000007
#define _GLIBCXX_DEBUG

string n;
int s;

ll solve(int k, int start, int size){
    if(k==1){
        return 9*(size-1) + n[start] - '0';
    }
    int next;
    for(next=start+1; next<s; next++){
        if(n[next] != '0') break;
    }
    if(next==s){
        if(k==2){
            return (size-1)*(size-2)/2*9*9 + (size-1)*9*(n[start]-'0'-1);
        }else{
            return (size-1)*(size-2)*(size-3)/6*9*9*9 + (size-1)*(size-2)/2*9*9*(n[start]-'0'-1);
        }
    }
    if(k==2){
        return (size-1)*(size-2)/2*9*9 + (n[start]-'0'-1)*(size-1)*9 + solve(1, next, s-next);
    }else{
        return (size-1)*(size-2)*(size-3)/6*9*9*9 + (n[start]-'0'-1)*(size-1)*(size-2)/2*9*9 + solve(2, next, s-next);
    }
}

int main(void){
    int k;
    cin >> n >> k;
    s = n.size();
    cout << solve(k, 0, s) << endl;
}