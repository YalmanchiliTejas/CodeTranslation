#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    REP(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    REP(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

int main()
{
    string S;
    cin >> S;
    string ans;
    if(S=="AAA" || S=="BBB"){
        ans = "No";
    }else{
        ans = "Yes";
    }
    cout << ans << endl;
}
